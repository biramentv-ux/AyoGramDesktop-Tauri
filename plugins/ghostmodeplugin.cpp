#include "ghostmodeplugin.h"
#include <QDebug>

GhostModePlugin::GhostModePlugin() : enabled(false) {}

GhostModePlugin::~GhostModePlugin() {}

QString GhostModePlugin::name() const {
    return "Ghost Mode";
}

QString GhostModePlugin::version() const {
    return "1.0";
}

void GhostModePlugin::initialize() {
    enabled = true;
    qDebug() << "Ghost Mode plugin initialized - скрит режим активиран";
}

void GhostModePlugin::unload() {
    enabled = false;
    qDebug() << "Ghost Mode plugin unloaded";
}