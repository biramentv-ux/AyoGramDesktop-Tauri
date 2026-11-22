#include "PrivateChannelSaverPlugin.h"
#include <QDebug>
#include <QFile>
#include <QDir>

PrivateChannelSaverPlugin::PrivateChannelSaverPlugin() : enabled(false) {}

PrivateChannelSaverPlugin::~PrivateChannelSaverPlugin() {}

QString PrivateChannelSaverPlugin::name() const {
    return "PrivateChannelSaver";
}

QString PrivateChannelSaverPlugin::version() const {
    return "1.0";
}

void PrivateChannelSaverPlugin::initialize() {
    enabled = true;
    qDebug() << "PrivateChannelSaver plugin initialized - запазване на съдържание от private канали";
}

void PrivateChannelSaverPlugin::unload() {
    enabled = false;
    qDebug() << "PrivateChannelSaver plugin unloaded";
}

bool PrivateChannelSaverPlugin::saveChannelContent(const QString &channelId, const QString &content) {
    if (!enabled) return false;
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/private_channels/" + channelId + ".txt";
    QDir dir(QFileInfo(path).absolutePath());
    dir.mkpath(".");
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        file.write(content.toUtf8());
        file.close();
        qDebug() << "Saved private channel content to" << path;
        return true;
    }
    return false;
}