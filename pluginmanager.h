#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QObject>
#include <QPluginLoader>
#include <QDir>
#include <QList>

class PluginManager : public QObject
{
    Q_OBJECT

public:
    static PluginManager& instance();
    
    void loadPlugins();
    void unloadPlugins();
    QList<QPluginLoader*> getLoadedPlugins();

private:
    PluginManager();
    ~PluginManager();
    
    QList<QPluginLoader*> loaders;
};

#endif // PLUGINMANAGER_H