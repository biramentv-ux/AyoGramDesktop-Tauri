#include "PluginInterface.h"
#include "MK_FuckPaymentsPlugin.h"
#include "FakePaymentInterceptorPlugin.h"
#include "UnlockStarsContentPlugin.h"
#include "LocalTelegramPremiumPlugin.h"

#include <iostream>

int main() {
    MK_FuckPaymentsPlugin mkPlugin;
    FakePaymentInterceptorPlugin fakePlugin;
    UnlockStarsContentPlugin unlockPlugin;
    LocalTelegramPremiumPlugin localPlugin;

    std::cout << "Loaded plugins:\n";
    std::cout << "1. " << mkPlugin.getName() << " - " << mkPlugin.getDescription() << "\n";
    std::cout << "2. " << fakePlugin.getName() << " - " << fakePlugin.getDescription() << "\n";
    std::cout << "3. " << unlockPlugin.getName() << " - " << unlockPlugin.getDescription() << "\n";
    std::cout << "4. " << localPlugin.getName() << " - " << localPlugin.getDescription() << "\n";

    return 0;
}