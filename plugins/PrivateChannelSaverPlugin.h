#ifndef PRIVATECHANNELSAVERPLUGIN_H
#define PRIVATECHANNELSAVERPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class PrivateChannelSaverPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "PrivateChannelSaverPlugin.json")

public:
    PrivateChannelSaverPlugin();
    ~PrivateChannelSaverPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

    bool saveChannelContent(const QString &channelId, const QString &content);

private:
    bool enabled;
};

#endif // PRIVATECHANNELSAVERPLUGIN_H