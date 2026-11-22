#include "ExteraAntiDeletePlugin.h"
#include <QDebug>

ExteraAntiDeletePlugin::ExteraAntiDeletePlugin() : enabled(false) {}

ExteraAntiDeletePlugin::~ExteraAntiDeletePlugin() {}

QString ExteraAntiDeletePlugin::name() const {
    return "ExteraAntiDelete";
}

QString ExteraAntiDeletePlugin::version() const {
    return "1.0";
}

void ExteraAntiDeletePlugin::initialize() {
    enabled = true;
    qDebug() << "ExteraAntiDelete plugin initialized - анти-изтриване активирано";
}

void ExteraAntiDeletePlugin::unload() {
    enabled = false;
    qDebug() << "ExteraAntiDelete plugin unloaded";
}