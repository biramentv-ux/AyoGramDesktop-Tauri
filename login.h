#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QLabel>

class TelegramClient;

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void onPhoneNext();
    void onCodeSubmit();
    void onQrLogin();

private:
    QLabel *titleLabel;
    QLineEdit *phoneEdit;
    QLineEdit *codeEdit;
    QPushButton *nextButton;
    QPushButton *loginButton;
    QLabel *qrLabel;
    QPushButton *qrButton;
    QVBoxLayout *mainLayout;
    TelegramClient *tgClient;
};

#endif // LOGIN_H
