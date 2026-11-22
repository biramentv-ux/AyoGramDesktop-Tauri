#include "ayu_settings.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

AyuSettings& AyuSettings::instance()
{
    static AyuSettings instance;
    return instance;
}

AyuSettings::AyuSettings(QObject *parent)
    : QObject(parent)
{
    // Initialize settings file path
    QString settingsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/ayu_settings.json";
    QDir dir(QFileInfo(settingsPath).absolutePath());
    if (!dir.exists()) {
        dir.mkpath(QFileInfo(settingsPath).absolutePath());
    }
    
    // Load existing settings or create default ones
    loadSettings();
}

AyuSettings::~AyuSettings()
{
}

bool AyuSettings::getGhostMode() const
{
    return m_settings.value("ghostMode", false).toBool();
}

void AyuSettings::setGhostMode(bool enabled)
{
    m_settings["ghostMode"] = enabled;
    saveSettings();
}

bool AyuSettings::getStreamerMode() const
{
    return m_settings.value("streamerMode", false).toBool();
}

void AyuSettings::setStreamerMode(bool enabled)
{
    m_settings["streamerMode"] = enabled;
    saveSettings();
}

bool AyuSettings::getLocalPremium() const
{
    return m_settings.value("localPremium", false).toBool();
}

void AyuSettings::setLocalPremium(bool enabled)
{
    m_settings["localPremium"] = enabled;
    saveSettings();
}

bool AyuSettings::getTranslator() const
{
    return m_settings.value("translator", false).toBool();
}

void AyuSettings::setTranslator(bool enabled)
{
    m_settings["translator"] = enabled;
    saveSettings();
}

int AyuSettings::getAppearance() const
{
    return m_settings.value("appearance", 0).toInt();
}

void AyuSettings::setAppearance(int appearance)
{
    m_settings["appearance"] = appearance;
    saveSettings();
}

bool AyuSettings::getMessageHistory() const
{
    return m_settings.value("messageHistory", false).toBool();
}

void AyuSettings::setMessageHistory(bool enabled)
{
    m_settings["messageHistory"] = enabled;
    saveSettings();
}

void AyuSettings::saveSettings()
{
    // Save settings to JSON file
    QJsonObject jsonObject;
    for (auto it = m_settings.begin(); it != m_settings.end(); ++it) {
        jsonObject[it.key()] = QJsonValue::fromVariant(it.value());
    }
    
    QJsonDocument jsonDoc(jsonObject);
    QString settingsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/ayu_settings.json";
    
    QFile file(settingsPath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
    }
}

void AyuSettings::loadSettings()
{
    // Load settings from JSON file
    QString settingsPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/ayu_settings.json";
    
    QFile file(settingsPath);
    if (file.open(QIODevice::ReadOnly)) {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc(QJsonDocument::fromJson(data));
        QJsonObject jsonObject = jsonDoc.object();
        
        for (auto it = jsonObject.begin(); it != jsonObject.end(); ++it) {
            m_settings[it.key()] = it.value().toVariant();
        }
        
        file.close();
    }
}
