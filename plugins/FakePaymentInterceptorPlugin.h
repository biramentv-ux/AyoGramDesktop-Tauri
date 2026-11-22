#ifndef FAKEPAYMENTINTERCEPTORPLUGIN_H
#define FAKEPAYMENTINTERCEPTORPLUGIN_H

#include "plugininterface.h"
#include <QObject>
#include <QString>

class FakePaymentInterceptorPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "FakePaymentInterceptorPlugin.json")

public:
    FakePaymentInterceptorPlugin();
    ~FakePaymentInterceptorPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

    // Intercept payment request
    bool interceptPaymentRequest(const QString &requestData);
    // Generate fake payment result
    QString generateFakePaymentResult(const QString &originalRequest);

private:
    bool enabled;
    QString lastRequest;
};

#endif // FAKEPAYMENTINTERCEPTORPLUGIN_H