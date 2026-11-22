#include "pluginmanager.h"
#include "plugins/plugininterface.h"
#include <QDebug>

PluginManager& PluginManager::instance() {
    static PluginManager instance;
    return instance;
}

PluginManager::PluginManager() {}

PluginManager::~PluginManager() {
    unloadPlugins();
}

void PluginManager::loadPlugins() {
    QDir pluginsDir(QApplication::applicationDirPath() + "/plugins");
    foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
        QString filePath = pluginsDir.absoluteFilePath(fileName);
        QPluginLoader *loader = new QPluginLoader(filePath);
        QObject *plugin = loader->instance();
        if (plugin) {
            qDebug() << "Loaded plugin:" << fileName;
            loaders.append(loader);
        } else {
            qDebug() << "Failed to load plugin:" << fileName << loader->errorString();
            delete loader;
        }
    }
}

void PluginManager::unloadPlugins() {
    foreach (QPluginLoader *loader, loaders) {
        loader->unload();
        delete loader;
    }
    loaders.clear();
}

QList<QPluginLoader*> PluginManager::getLoadedPlugins() {
    return loaders;
}