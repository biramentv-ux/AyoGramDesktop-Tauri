#ifndef PRIVATEGROUPSAVERPLUGIN_H
#define PRIVATEGROUPSAVERPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class PrivateGroupSaverPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "PrivateGroupSaverPlugin.json")

public:
    PrivateGroupSaverPlugin();
    ~PrivateGroupSaverPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

    bool saveGroupContent(const QString &groupId, const QString &content);

private:
    bool enabled;
};

#endif // PRIVATEGROUPSAVERPLUGIN_H