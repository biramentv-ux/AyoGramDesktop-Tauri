#include "UnlockStarsContentPlugin.h"
#include <QDebug>

UnlockStarsContentPlugin::UnlockStarsContentPlugin() : enabled(false) {}

UnlockStarsContentPlugin::~UnlockStarsContentPlugin() {}

QString UnlockStarsContentPlugin::name() const {
    return "UnlockStarsContent";
}

QString UnlockStarsContentPlugin::version() const {
    return "1.0";
}

void UnlockStarsContentPlugin::initialize() {
    enabled = true;
    qDebug() << "UnlockStarsContent plugin initialized - отключване на star съдържание";
}

void UnlockStarsContentPlugin::unload() {
    enabled = false;
    qDebug() << "UnlockStarsContent plugin unloaded";
}

bool UnlockStarsContentPlugin::unlockStarContent(const QString &contentId) {
    if (!enabled) return false;
    qDebug() << "Unlocking star content:" << contentId;
    return true;
}

bool UnlockStarsContentPlugin::unlockStarContentEx(const QString &contentId, const QString &userId, const QString &chatId) {
    if (!enabled) return false;
    qDebug() << "Unlocking star content:" << contentId << "for user:" << userId << "in chat:" << chatId;
    return true;
}