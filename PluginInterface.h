#pragma once
#include <QString>
#include <QObject>

class PluginInterface {
public:
    virtual ~PluginInterface() {}
    virtual QString name() const = 0;
    virtual QString version() const = 0;
    virtual bool initialize() = 0;
    virtual void shutdown() = 0;
};

#define PluginFactoryInterface IPluginFactory
class IPluginFactory {
public:
    virtual ~IPluginFactory() {}
    virtual PluginInterface* createPlugin() = 0;
};

#define PluginInterface_iid "com.dyrak_dgram.plugin.interface/1.0"
Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)
