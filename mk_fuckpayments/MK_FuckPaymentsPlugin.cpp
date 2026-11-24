// MK_FuckPaymentsPlugin.cpp
// Plugin to bypass Telegram Premium payments

#include "MK_FuckPaymentsPlugin.h"
#include <QDebug>

MK_FuckPaymentsPlugin::MK_FuckPaymentsPlugin(QObject *parent) : QObject(parent) {
    qDebug() << "MK_FuckPaymentsPlugin initialized";
}

void MK_FuckPaymentsPlugin::bypassPremium(QVariantMap &data) {
    // Bypass premium checks
    data["is_premium"] = true;
    data["premium_expiry"] = "9999-12-31";
    qDebug() << "Premium bypass activated";
}