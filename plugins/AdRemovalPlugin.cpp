#include "AdRemovalPlugin.h"
#include <QDebug>

AdRemovalPlugin::AdRemovalPlugin() : enabled(false) {}

AdRemovalPlugin::~AdRemovalPlugin() {}

QString AdRemovalPlugin::name() const {
    return "AdRemoval";
}

QString AdRemovalPlugin::version() const {
    return "1.0";
}

void AdRemovalPlugin::initialize() {
    enabled = true;
    qDebug() << "AdRemoval plugin initialized - премахване на реклами";
}

void AdRemovalPlugin::unload() {
    enabled = false;
    qDebug() << "AdRemoval plugin unloaded";
}

bool AdRemovalPlugin::removeAds() {
    if (!enabled) return false;
    qDebug() << "Removing ads from UI";
    return true;
}