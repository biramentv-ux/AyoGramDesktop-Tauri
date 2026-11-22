#include "telegramclient.h"
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QSettings>

TelegramClient::TelegramClient(QObject *parent)
    : QObject(parent), isAuthenticated(false)
{
    pollTimer = new QTimer(this);
    connect(pollTimer, &QTimer::timeout, this, [this](){ /* poll TDLib */ });
    loadSession();
}

TelegramClient::~TelegramClient()
{
    saveSession();
    shutdownTdlib();
}

void TelegramClient::start()
{
    initializeTdlib();
    qDebug() << "TelegramClient started";
    pollTimer->start(100);
}

void TelegramClient::stop()
{
    pollTimer->stop();
    shutdownTdlib();
}

void TelegramClient::loadSession()
{
    QSettings settings("dyrakDGram", "dyrakDGram");
    phoneNumber = settings.value("telegram/phone", "").toString();
    isAuthenticated = settings.value("telegram/authenticated", false).toBool();
}

void TelegramClient::saveSession()
{
    QSettings settings("dyrakDGram", "dyrakDGram");
    settings.setValue("telegram/phone", phoneNumber);
    settings.setValue("telegram/authenticated", isAuthenticated);
    emit sessionSaved();
}

void TelegramClient::initializeTdlib()
{
    // Тук се инициализира TDLib с параметри:
    // api_id, api_hash, database_directory, files_directory
    // В реална имплементация се използва td::Client::create() и се четат updates през сокет
    qDebug() << "TDLib инициализиран - api_id/api_hash от настройки";
}

void TelegramClient::shutdownTdlib()
{
    qDebug() << "TDLib спрян";
}

void TelegramClient::requestQrLogin()
{
    // TDLib заявка: {"@type":"requestQrLogin"}
    QJsonObject req;
    req["@type"] = "requestQrLogin";
    sendRequest(req);
}

void TelegramClient::setPhoneNumber(const QString &phone)
{
    phoneNumber = phone;
}

void TelegramClient::signInByPhone(const QString &phone)
{
    phoneNumber = phone;
    QJsonObject req;
    req["@type"] = "checkAuthenticationBotToken"; // placeholder
    // реално: {"@type":"checkAuthenticationPhoneNumber", "phone_number": phone}
    sendRequest(req);
    emit codeRequested(phone);
}

void TelegramClient::sendCode(const QString &code)
{
    QJsonObject req;
    req["@type"] = "checkAuthenticationCode";
    req["phone_number"] = phoneNumber;
    req["code"] = code;
    sendRequest(req);
}

void TelegramClient::sendRequest(const QJsonObject &request)
{
    // Публикувай заявка към TDLib
    Q_UNUSED(request);
}

void TelegramClient::processUpdate(const QJsonObject &update)
{
    QString type = update["@type"].toString();
    if (type == "updateAuthorizationState") {
        handleAuthState(update["authorization_state"].toObject());
    } else if (type == "updateQrLoginCode") {
        QString qrData = update["authentication_code_info"].toObject()["qr_code"].toString();
        QString link = update["authentication_code_info"].toObject()["token"].toString();
        emit qrCodeReceived(qrData, link);
    }
}

void TelegramClient::handleAuthState(const QJsonObject &auth)
{
    QString state = auth["@type"].toString();
    emit authStateChanged(state);

    if (state == "authorizationStateReady") {
        isAuthenticated = true;
        saveSession();
        emit loggedIn();
    } else if (state == "authorizationStateWaitPhoneNumber") {
        emit phoneRequested();
    } else if (state == "authorizationStateWaitCode") {
        emit codeRequested(phoneNumber);
    } else if (state == "authorizationStateWaitPassword") {
        // TODO: 2FA
    } else if (state == "authorizationStateLoggingOut" || state == "authorizationStateLoggedOut") {
        isAuthenticated = false;
        saveSession();
        emit loggedOut();
    }
}
