#ifndef EXTERACHATLOGGERPLUGIN_H
#define EXTERACHATLOGGERPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class ExteraChatLoggerPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "ExteraChatLoggerPlugin.json")

public:
    ExteraChatLoggerPlugin();
    ~ExteraChatLoggerPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // EXTERACHATLOGGERPLUGIN_H