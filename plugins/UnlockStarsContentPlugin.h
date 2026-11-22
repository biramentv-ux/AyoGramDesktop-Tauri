#ifndef UNLOCKSTARSCONTENTPLUGIN_H
#define UNLOCKSTARSCONTENTPLUGIN_H

#include "plugininterface.h"
#include <QObject>

class UnlockStarsContentPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID PluginInterface_iid FILE "UnlockStarsContentPlugin.json")

public:
    UnlockStarsContentPlugin();
    ~UnlockStarsContentPlugin();

    QString name() const override;
    QString version() const override;
    void initialize() override;
    void unload() override;

    bool unlockStarContent(const QString &contentId);
    bool unlockStarContentEx(const QString &contentId, const QString &userId, const QString &chatId);

private:
    bool enabled;
};

#endif // UNLOCKSTARSCONTENTPLUGIN_H