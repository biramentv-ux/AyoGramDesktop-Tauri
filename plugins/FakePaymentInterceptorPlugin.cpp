#include "FakePaymentInterceptorPlugin.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

FakePaymentInterceptorPlugin::FakePaymentInterceptorPlugin() : enabled(false) {}

FakePaymentInterceptorPlugin::~FakePaymentInterceptorPlugin() {}

QString FakePaymentInterceptorPlugin::name() const {
    return "FakePaymentInterceptor";
}

QString FakePaymentInterceptorPlugin::version() const {
    return "1.0";
}

void FakePaymentInterceptorPlugin::initialize() {
    enabled = true;
    qDebug() << "FakePaymentInterceptor plugin initialized - прихващане на плащания активирано";
}

void FakePaymentInterceptorPlugin::unload() {
    enabled = false;
    qDebug() << "FakePaymentInterceptor plugin unloaded";
}

bool FakePaymentInterceptorPlugin::interceptPaymentRequest(const QString &requestData) {
    if (!enabled) return false;
    
    // Detect TL_payments_sendStarsForm request
    if (requestData.contains("TL_payments_sendStarsForm")) {
        lastRequest = requestData;
        qDebug() << "Intercepted payment request: TL_payments_sendStarsForm";
        return true; // Intercepted
    }
    return false;
}

QString FakePaymentInterceptorPlugin::generateFakePaymentResult(const QString &originalRequest) {
    if (!enabled) return originalRequest;
    
    // Create fake TL_payments_paymentResult response
    QJsonObject fakeResult;
    fakeResult["@type"] = "TL_payments_paymentResult";
    fakeResult["update_id"] = 123456;
    fakeResult["payment_id"] = "fake_payment_" + QString::number(qrand() % 10000);
    fakeResult["success"] = true;
    fakeResult["status"] = "paid";
    fakeResult["message"] = "Успешно плащане!";
    
    QJsonDocument doc(fakeResult);
    QString fakeResponse = doc.toJson(QJsonDocument::Compact);
    
    qDebug() << "Generated fake payment result for client";
    return fakeResponse;
}