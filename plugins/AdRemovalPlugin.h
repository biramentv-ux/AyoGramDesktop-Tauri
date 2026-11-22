#ifndef ADREMOVALPLUGIN_H
#define ADREMOVALPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class AdRemovalPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "AdRemovalPlugin.json")

public:
    AdRemovalPlugin();
    ~AdRemovalPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

    bool removeAds();

private:
    bool enabled;
};

#endif // ADREMOVALPLUGIN_H