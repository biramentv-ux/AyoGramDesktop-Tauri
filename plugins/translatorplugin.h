#ifndef TRANSLATORPLUGIN_H
#define TRANSLATORPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class TranslatorPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "translatorplugin.json")

public:
    TranslatorPlugin();
    ~TranslatorPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // TRANSLATORPLUGIN_H