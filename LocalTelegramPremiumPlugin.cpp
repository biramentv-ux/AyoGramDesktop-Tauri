#include "LocalTelegramPremiumPlugin.h"
#include <iostream>

void LocalTelegramPremiumPlugin::initialize() {
    std::cout << "[LocalTelegramPremium] Plugin initialized" << std::endl;
}

void LocalTelegramPremiumPlugin::cleanup() {
    std::cout << "[LocalTelegramPremium] Plugin cleaned up" << std::endl;
}

bool LocalTelegramPremiumPlugin::handleMessage(const Message& message) {
    if (message.isSystem()) {
        return false;
    }
    
    if (message.getType() == MessageType::USER_UPDATE) {
        User user = message.getUser();
        if (isPremiumUser(user)) {
            grantPremiumFeatures(user);
            return true;
        }
    }
    
    return false;
}

bool LocalTelegramPremiumPlugin::isPremiumUser(const User& user) {
    return user.isPremium();
}

void LocalTelegramPremiumPlugin::grantPremiumFeatures(User& user) {
    user.setPremium(true);
    user.setPremiumUntil(0x7FFFFFFFFFFFFFFF);
}
