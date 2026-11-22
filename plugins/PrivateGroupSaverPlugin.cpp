#include "PrivateGroupSaverPlugin.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QStandardPaths>

PrivateGroupSaverPlugin::PrivateGroupSaverPlugin() : enabled(false) {}

PrivateGroupSaverPlugin::~PrivateGroupSaverPlugin() {}

QString PrivateGroupSaverPlugin::name() const {
    return "PrivateGroupSaver";
}

QString PrivateGroupSaverPlugin::version() const {
    return "1.0";
}

void PrivateGroupSaverPlugin::initialize() {
    enabled = true;
    qDebug() << "PrivateGroupSaver plugin initialized - запазване на съдържание от private групи";
}

void PrivateGroupSaverPlugin::unload() {
    enabled = false;
    qDebug() << "PrivateGroupSaver plugin unloaded";
}

bool PrivateGroupSaverPlugin::saveGroupContent(const QString &groupId, const QString &content) {
    if (!enabled) return false;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/private_groups/" + groupId + ".txt";
    QDir dir(QFileInfo(path).absolutePath());
    dir.mkpath(".");
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        file.write(content.toUtf8());
        file.close();
        qDebug() << "Saved private group content to" << path;
        return true;
    }
    return false;
}