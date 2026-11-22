#ifndef AYU_TRANSLATOR_H
#define AYU_TRANSLATOR_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QTranslator>

class AyuTranslator : public QObject
{
    Q_OBJECT

public:
    static AyuTranslator& instance();
    
    // Initialize translator
    void initializeTranslator();
    
    // Translate text
    QString translateText(const QString& text);
    
    // Set translation provider
    void setTranslationProvider(const QString& provider);
    
    // Get current translation provider
    QString getTranslationProvider() const;
    
    // Clear translation cache
    void clearCache();
    
    // Load translation file
    bool loadTranslationFile(const QString& language, const QString& filename);
    
private:
    explicit AyuTranslator(QObject *parent = nullptr);
    ~AyuTranslator();
    
    QTranslator* translator;
    QString currentProvider;
    QMap<QString, QString> translationCache;
};

#endif // AYU_TRANSLATOR_H
