#ifndef MEDIAPREVIEWPLUGIN_H
#define MEDIAPREVIEWPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class MediaPreviewPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "mediapreviewplugin.json")

public:
    MediaPreviewPlugin();
    ~MediaPreviewPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // MEDIAPREVIEWPLUGIN_H