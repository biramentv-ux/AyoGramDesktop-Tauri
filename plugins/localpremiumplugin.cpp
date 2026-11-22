#include "localpremiumplugin.h"
#include <QDebug>

LocalPremiumPlugin::LocalPremiumPlugin() : enabled(false) {}

LocalPremiumPlugin::~LocalPremiumPlugin() {}

QString LocalPremiumPlugin::name() const {
    return "Local Premium";
}

QString LocalPremiumPlugin::version() const {
    return "1.0";
}

void LocalPremiumPlugin::initialize() {
    enabled = true;
    qDebug() << "Local Premium plugin initialized - локален Premium активиран";
}

void LocalPremiumPlugin::unload() {
    enabled = false;
    qDebug() << "Local Premium plugin unloaded";
}