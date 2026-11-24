#pragma once

#include <QObject>
#include "PluginInterface.h"

class LocalTelegramPremiumPlugin : public QObject, public PluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.telegram.desktop.LocalTelegramPremiumPlugin")
    Q_INTERFACES(PluginInterface)

public:
    LocalTelegramPremiumPlugin(QObject *parent = nullptr);
    ~LocalTelegramPremiumPlugin();

    // PluginInterface
    QString name() const override { return "LocalTelegramPremium"; }
    QString description() const override { return "Enables local Telegram Premium features without server validation"; }

    void init() override;
    void deinit() override;
    bool isAvailable() const override { return true; }

private slots:
    void onPremiumFeatureRequest(const QVariant &data);
    void onPremiumValidationRequest(const QVariant &data);

signals:
    void premiumFeatureGranted(const QVariant &data);
    void premiumValidationSuccess(const QVariant &data);
};