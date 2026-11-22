#include "filtersplugin.h"
#include <QDebug>

FiltersPlugin::FiltersPlugin() : enabled(false) {}

FiltersPlugin::~FiltersPlugin() {}

QString FiltersPlugin::name() const {
    return "Filters";
}

QString FiltersPlugin::version() const {
    return "1.0";
}

void FiltersPlugin::initialize() {
    enabled = true;
    qDebug() << "Filters plugin initialized - филтри активирани";
}

void FiltersPlugin::unload() {
    enabled = false;
    qDebug() << "Filters plugin unloaded";
}