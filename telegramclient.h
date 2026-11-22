#ifndef TELEGRAMCLIENT_H
#define TELEGRAMCLIENT_H

#include <QObject>
#include <QTimer>
#include <QMutex>
#include <QQueue>
#include <QJsonObject>

class TelegramClient : public QObject
{
    Q_OBJECT
public:
    explicit TelegramClient(QObject *parent = nullptr);
    ~TelegramClient();

    void start();
    void stop();

    // Auth API
    void requestQrLogin();
    void setPhoneNumber(const QString &phone);
    void sendCode(const QString &code);
    void signInByPhone(const QString &phone);

signals:
    void authStateChanged(const QString &state);
    void qrCodeReceived(const QString &qrData, const QString &qrLink);
    void phoneRequested();
    void codeRequested(const QString &phone);
    void authNeededError(const QString &error);
    void loggedIn();
    void loggedOut();
    void sessionSaved();

private slots:
    void processUpdate(const QJsonObject &update);

private:
    void loadSession();
    void saveSession();
    void handleAuthState(const QJsonObject &auth);
    void sendRequest(const QJsonObject &request);
    // TDLib integration placeholder
    void initializeTdlib();
    void shutdownTdlib();

    QString phoneNumber;
    bool isAuthenticated;
    QTimer *pollTimer;
};

#endif // TELEGRAMCLIENT_H
