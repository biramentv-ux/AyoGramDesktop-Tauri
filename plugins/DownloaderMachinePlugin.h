#ifndef DOWNLOADERMACHINEPLUGIN_H
#define DOWNLOADERMACHINEPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class DownloaderMachinePlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "DownloaderMachinePlugin.json")

public:
    DownloaderMachinePlugin();
    ~DownloaderMachinePlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

    bool downloadSpotifyContent(const QString &url);
    bool downloadSpotifyContentEx(const QString &url, const QString &format, const QString &bitrate);

private:
    bool enabled;
};

#endif // DOWNLOADERMACHINEPLUGIN_H