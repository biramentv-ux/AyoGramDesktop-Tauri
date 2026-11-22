#include "MK_FuckPaymentsPlugin.h"
#include <QDebug>

MK_FuckPaymentsPlugin::MK_FuckPaymentsPlugin() : enabled(false) {}

MK_FuckPaymentsPlugin::~MK_FuckPaymentsPlugin() {}

QString MK_FuckPaymentsPlugin::name() const {
    return "MK_FuckPayments";
}

QString MK_FuckPaymentsPlugin::version() const {
    return "1.0";
}

void MK_FuckPaymentsPlugin::initialize() {
    enabled = true;
    qDebug() << "MK_FuckPayments plugin initialized - fake_stars активиран";
}

void MK_FuckPaymentsPlugin::unload() {
    enabled = false;
    qDebug() << "MK_FuckPayments plugin unloaded";
}