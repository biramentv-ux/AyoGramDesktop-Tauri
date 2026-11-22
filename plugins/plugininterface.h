#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include <QString>
#include <QObject>

class PluginInterface
{
public:
    virtual ~PluginInterface() {}
    virtual QString name() const = 0;
    virtual QString version() const = 0;
    virtual void initialize() = 0;
    virtual void unload() = 0;
};

#define PluginInterface_iid "org.ayugram.PluginInterface/1.0"
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGININTERFACE_H