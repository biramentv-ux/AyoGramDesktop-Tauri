#include "ExteraMediaSaverPlugin.h"
#include <QDebug>

ExteraMediaSaverPlugin::ExteraMediaSaverPlugin() : enabled(false) {}

ExteraMediaSaverPlugin::~ExteraMediaSaverPlugin() {}

QString ExteraMediaSaverPlugin::name() const {
    return "ExteraMediaSaver";
}

QString ExteraMediaSaverPlugin::version() const {
    return "1.0";
}

void ExteraMediaSaverPlugin::initialize() {
    enabled = true;
    qDebug() << "ExteraMediaSaver plugin initialized - автоматично запазване на медия";
}

void ExteraMediaSaverPlugin::unload() {
    enabled = false;
    qDebug() << "ExteraMediaSaver plugin unloaded";
}