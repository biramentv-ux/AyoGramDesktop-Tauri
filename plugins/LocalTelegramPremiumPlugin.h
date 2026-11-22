#ifndef LOCALTELEGRAMPREMIUMPLUGIN_H
#define LOCALTELEGRAMPREMIUMPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class LocalTelegramPremiumPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "LocalTelegramPremiumPlugin.json")

public:
    LocalTelegramPremiumPlugin();
    ~LocalTelegramPremiumPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

    bool enablePremiumFeatures();

private:
    bool enabled;
};

#endif // LOCALTELEGRAMPREMIUMPLUGIN_H