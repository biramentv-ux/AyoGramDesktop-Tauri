#include "mediapreviewplugin.h"
#include <QDebug>

MediaPreviewPlugin::MediaPreviewPlugin() : enabled(false) {}

MediaPreviewPlugin::~MediaPreviewPlugin() {}

QString MediaPreviewPlugin::name() const {
    return "Media Preview";
}

QString MediaPreviewPlugin::version() const {
    return "1.0";
}

void MediaPreviewPlugin::initialize() {
    enabled = true;
    qDebug() << "Media Preview plugin initialized - медийни предварителни прегледи активирани";
}

void MediaPreviewPlugin::unload() {
    enabled = false;
    qDebug() << "Media Preview plugin unloaded";
}