#ifndef FILTERSPLUGIN_H
#define FILTERSPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class FiltersPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "filtersplugin.json")

public:
    FiltersPlugin();
    ~FiltersPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

private:
    bool enabled;
};

#endif // FILTERSPLUGIN_H