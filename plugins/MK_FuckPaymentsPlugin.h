#ifndef MK_FUCKPAYMENTSPLUGIN_H
#define MK_FUCKPAYMENTSPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class MK_FuckPaymentsPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "MK_FuckPaymentsPlugin.json")

public:
    MK_FuckPaymentsPlugin();
    ~MK_FuckPaymentsPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // MK_FUCKPAYMENTSPLUGIN_H