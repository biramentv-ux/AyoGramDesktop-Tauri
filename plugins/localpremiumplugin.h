#ifndef LOCALPREMIUMPLUGIN_H
#define LOCALPREMIUMPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class LocalPremiumPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "localpremiumplugin.json")

public:
    LocalPremiumPlugin();
    ~LocalPremiumPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // LOCALPREMIUMPLUGIN_H