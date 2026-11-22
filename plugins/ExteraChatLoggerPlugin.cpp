#include "ExteraChatLoggerPlugin.h"
#include <QDebug>

ExteraChatLoggerPlugin::ExteraChatLoggerPlugin() : enabled(false) {}

ExteraChatLoggerPlugin::~ExteraChatLoggerPlugin() {}

QString ExteraChatLoggerPlugin::name() const {
    return "ExteraChatLogger";
}

QString ExteraChatLoggerPlugin::version() const {
    return "1.0";
}

void ExteraChatLoggerPlugin::initialize() {
    enabled = true;
    qDebug() << "ExteraChatLogger plugin initialized - логване на чатове активирано";
}

void ExteraChatLoggerPlugin::unload() {
    enabled = false;
    qDebug() << "ExteraChatLogger plugin unloaded";
}