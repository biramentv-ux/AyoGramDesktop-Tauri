#ifndef EXTERAANTIDELETEPLUGIN_H
#define EXTERAANTIDELETEPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class ExteraAntiDeletePlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "ExteraAntiDeletePlugin.json")

public:
    ExteraAntiDeletePlugin();
    ~ExteraAntiDeletePlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // EXTERAANTIDELETEPLUGIN_H