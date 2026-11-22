#include "LocalTelegramPremiumPlugin.h"
#include <QDebug>

LocalTelegramPremiumPlugin::LocalTelegramPremiumPlugin() : enabled(false) {}

LocalTelegramPremiumPlugin::~LocalTelegramPremiumPlugin() {}

QString LocalTelegramPremiumPlugin::name() const {
    return "LocalTelegramPremium";
}

QString LocalTelegramPremiumPlugin::version() const {
    return "1.0";
}

void LocalTelegramPremiumPlugin::initialize() {
    enabled = true;
    qDebug() << "LocalTelegramPremium plugin initialized - локален Premium активиран";
}

void LocalTelegramPremiumPlugin::unload() {
    enabled = false;
    qDebug() << "LocalTelegramPremium plugin unloaded";
}

bool LocalTelegramPremiumPlugin::enablePremiumFeatures() {
    if (!enabled) return false;
    qDebug() << "Enabling local Telegram Premium features";
    return true;
}