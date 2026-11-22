#ifndef EXTERAMEDIASAVERPLUGIN_H
#define EXTERAMEDIASAVERPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class ExteraMediaSaverPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "ExteraMediaSaverPlugin.json")

public:
    ExteraMediaSaverPlugin();
    ~ExteraMediaSaverPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // EXTERAMEDIASAVERPLUGIN_H