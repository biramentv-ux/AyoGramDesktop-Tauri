/**
 * LocalTelegramPremiumPlugin
 * 
 * Provides local Telegram Premium features without requiring a Premium subscription
 */

#pragma once

#include "PluginInterface.h"

class LocalTelegramPremiumPlugin : public PluginInterface {
public:
    LocalTelegramPremiumPlugin();
    ~LocalTelegramPremiumPlugin();

    std::string getName() const override;
    std::string getDescription() const override;
    std::vector<std::string> getFeatures() const override;
    bool isEnabled() const override;
    void enable() override;
    void disable() override;
    int getPriority() const override;
    bool shouldIntercept(std::string request) override;
    std::string interceptAndModify(std::string request) override;
    void onMessageReceived(std::string message) override;
};

PluginInterface* createPlugin();