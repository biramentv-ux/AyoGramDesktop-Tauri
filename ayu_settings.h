#ifndef AYU_SETTINGS_H
#define AYU_SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QVariant>
#include <QMap>
#include <QJsonObject>
#include <QJsonDocument>

class AyuSettings : public QObject
{
    Q_OBJECT

public:
    static AyuSettings& instance();
    
    // Ghost mode settings
    bool getGhostMode() const;
    void setGhostMode(bool enabled);
    
    // Streamer mode settings
    bool getStreamerMode() const;
    void setStreamerMode(bool enabled);
    
    // Local Premium settings
    bool getLocalPremium() const;
    void setLocalPremium(bool enabled);
    
    // Translator settings
    bool getTranslator() const;
    void setTranslator(bool enabled);
    
    // Appearance settings
    int getAppearance() const;
    void setAppearance(int appearance);
    
    // Message history settings
    bool getMessageHistory() const;
    void setMessageHistory(bool enabled);
    
    // Save all settings
    void saveSettings();
    
    // Load all settings
    void loadSettings();

private:
    explicit AyuSettings(QObject *parent = nullptr);
    ~AyuSettings();
    
    QSettings settings;
    QMap<QString, QVariant> m_settings;
};

#endif // AYU_SETTINGS_H
