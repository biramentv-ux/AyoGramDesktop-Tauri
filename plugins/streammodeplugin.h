#ifndef STREAMMODEPLUGIN_H
#define STREAMMODEPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class StreamModePlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "streammodeplugin.json")

public:
    StreamModePlugin();
    ~StreamModePlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // STREAMMODEPLUGIN_H