#include "login.h"
#include "telegramclient.h"
#include <QMessageBox>
#include <QPixmap>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent), tgClient(new TelegramClient(this))
{
    setWindowTitle("Вход в Telegram");
    setFixedSize(400, 550);

    titleLabel = new QLabel("Вход в оригинален Telegram акаунт", this);
    titleLabel->setAlignment(Qt::AlignCenter);

    phoneEdit = new QLineEdit(this);
    phoneEdit->setPlaceholderText("+359xxxxxxxx");
    phoneEdit->setInputMask("+000000000000");

    nextButton = new QPushButton("Продължи с телефон", this);
    connect(nextButton, &QPushButton::clicked, this, &LoginDialog::onPhoneNext);

    codeEdit = new QLineEdit(this);
    codeEdit->setPlaceholderText("Код за потвърждение");
    codeEdit->setVisible(false);

    loginButton = new QPushButton("Вход", this);
    loginButton->setVisible(false);
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::onCodeSubmit);

    qrButton = new QPushButton("Сканирай QR код за вход", this);
    connect(qrButton, &QPushButton::clicked, this, &LoginDialog::onQrLogin);

    qrLabel = new QLabel(this);
    qrLabel->setAlignment(Qt::AlignCenter);
    qrLabel->setText("QR код ще се покаже тук след стартиране на сесия");
    qrLabel->setVisible(false);
    qrLabel->setMinimumHeight(200);

    // Connect TDLib signals
    connect(tgClient, &TelegramClient::authStateChanged, this, [this](const QString &state){
        qDebug() << "Auth state:" << state;
    });
    connect(tgClient, &TelegramClient::qrCodeReceived, this, [this](const QString &qrData, const QString &link){
        qrLabel->setPixmap(QPixmap::fromImage(QImage::fromData(qrData.toUtf8()))); // placeholder
        qrLabel->setText("Сканирай QR с Telegram клиента");
        qrLabel->setVisible(true);
    });
    connect(tgClient, &TelegramClient::loggedIn, this, [this](){ accept(); });
    connect(tgClient, &TelegramClient::loggedOut, this, [this](){ reject(); });

    tgClient->start();

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(phoneEdit);
    mainLayout->addWidget(nextButton);
    mainLayout->addWidget(codeEdit);
    mainLayout->addWidget(loginButton);
    mainLayout->addWidget(qrButton);
    mainLayout->addWidget(qrLabel);

    setLayout(mainLayout);
}

void LoginDialog::onPhoneNext()
{
    QString phone = phoneEdit->text().replace(" ", "").replace("-", "");
    if (phone.length() < 7) {
        QMessageBox::warning(this, "Грешка", "Въведете валиден телефонен номер");
        return;
    }
    tgClient->setPhoneNumber(phone);
    tgClient->signInByPhone(phone);
    codeEdit->setVisible(true);
    loginButton->setVisible(true);
    QMessageBox::information(this, "Код изпратен", "SMS код е изпратен на " + phone + "\nВъведете кода за продължаване");
}

void LoginDialog::onCodeSubmit()
{
    if (codeEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Грешка", "Въведете кода за потвърждение");
        return;
    }
    tgClient->sendCode(codeEdit->text());
    // TDLib ще емитира loggedIn при authStateReady
}

LoginDialog::~LoginDialog() {}

void LoginDialog::onQrLogin()
{
    tgClient->requestQrLogin();
    qrLabel->setVisible(true);
    QMessageBox::information(this, "QR вход", "Покажете този QR с вашия Telegram клиент за бързо свързване.");
}
