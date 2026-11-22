#ifndef GHOSTMODEPLUGIN_H
#define GHOSTMODEPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class GhostModePlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "ghostmodeplugin.json")

public:
    GhostModePlugin();
    ~GhostModePlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // GHOSTMODEPLUGIN_H