#include "streammodeplugin.h"
#include <QDebug>

StreamModePlugin::StreamModePlugin() : enabled(false) {}

StreamModePlugin::~StreamModePlugin() {}

QString StreamModePlugin::name() const {
    return "Stream Mode";
}

QString StreamModePlugin::version() const {
    return "1.0";
}

void StreamModePlugin::initialize() {
    enabled = true;
    qDebug() << "Stream Mode plugin initialized - режим на стриймър активиран";
}

void StreamModePlugin::unload() {
    enabled = false;
    qDebug() << "Stream Mode plugin unloaded";
}