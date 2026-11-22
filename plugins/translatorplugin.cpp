#include "translatorplugin.h"
#include <QDebug>

TranslatorPlugin::TranslatorPlugin() : enabled(false) {}

TranslatorPlugin::~TranslatorPlugin() {}

QString TranslatorPlugin::name() const {
    return "Translator";
}

QString TranslatorPlugin::version() const {
    return "1.0";
}

void TranslatorPlugin::initialize() {
    enabled = true;
    qDebug() << "Translator plugin initialized - преводач активиран";
}

void TranslatorPlugin::unload() {
    enabled = false;
    qDebug() << "Translator plugin unloaded";
}