#pragma once
#include "PluginInterface.h"

class LocalTelegramPremiumPlugin : public PluginInterface {
public:
    const char* getPluginName() const override { return "LocalTelegramPremiumPlugin"; }
    void initialize() override;
    void cleanup() override;
    
    bool handleMessage(const Message& message) override;
    
private:
    bool isPremiumUser(const User& user);
    void grantPremiumFeatures(User& user);
};
