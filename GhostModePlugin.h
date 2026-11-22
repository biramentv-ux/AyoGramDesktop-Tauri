#pragma once
#include "../PluginInterface/PluginInterface.h"
#include <QObject>

class GhostModePlugin : public QObject, public PluginInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "ghostmode.json")
    Q_INTERFACES(PluginInterface)
public:
    QString name() const override { return "GhostMode"; }
    QString version() const override { return "1.0.0"; }
    bool initialize() override { return true; }
    void shutdown() override {}
};
