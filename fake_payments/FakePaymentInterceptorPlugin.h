#pragma once

#include <QObject>
#include <QVariantMap>

class FakePaymentInterceptorPlugin : public QObject {
    Q_OBJECT
public:
    explicit FakePaymentInterceptorPlugin(QObject *parent = nullptr);
    
public slots:
    void interceptPayment(QVariantMap &data);
};