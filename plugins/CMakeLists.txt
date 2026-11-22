# Plugins CMake configuration

find_package(Qt6 REQUIRED COMPONENTS Core)

set(PLUGIN_OUTPUT_DIR ${CMAKE_BINARY_DIR}/plugins)
file(MAKE_DIRECTORY ${PLUGIN_OUTPUT_DIR})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Ghost Mode Plugin
add_library(ghostmodeplugin SHARED
    ghostmodeplugin.cpp
    ghostmodeplugin.h
)
target_link_libraries(ghostmodeplugin PRIVATE Qt6::Core)
set_target_properties(ghostmodeplugin PROPERTIES
    OUTPUT_NAME "ghostmodeplugin"
    PREFIX ""
)
add_custom_command(TARGET ghostmodeplugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ghostmodeplugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:ghostmodeplugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/ghostmodeplugin.json ${PLUGIN_OUTPUT_DIR}/ghostmodeplugin.json
    COMMENT "Copying ghostmodeplugin to ${PLUGIN_OUTPUT_DIR}"

# Stream Mode Plugin
add_library(streammodeplugin SHARED
    streammodeplugin.cpp
    streammodeplugin.h
)
target_link_libraries(streammodeplugin PRIVATE Qt6::Core)
set_target_properties(streammodeplugin PROPERTIES
    OUTPUT_NAME "streammodeplugin"
    PREFIX ""
)
add_custom_command(TARGET streammodeplugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:streammodeplugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:streammodeplugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/streammodeplugin.json ${PLUGIN_OUTPUT_DIR}/streammodeplugin.json
    COMMENT "Copying streammodeplugin to ${PLUGIN_OUTPUT_DIR}"

# Local Premium Plugin
add_library(localpremiumplugin SHARED
    localpremiumplugin.cpp
    localpremiumplugin.h
)
target_link_libraries(localpremiumplugin PRIVATE Qt6::Core)
set_target_properties(localpremiumplugin PROPERTIES
    OUTPUT_NAME "localpremiumplugin"
    PREFIX ""
)
add_custom_command(TARGET localpremiumplugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:localpremiumplugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:localpremiumplugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/localpremiumplugin.json ${PLUGIN_OUTPUT_DIR}/localpremiumplugin.json
    COMMENT "Copying localpremiumplugin to ${PLUGIN_OUTPUT_DIR}"

# Translator Plugin
add_library(translatorplugin SHARED
    translatorplugin.cpp
    translatorplugin.h
)
target_link_libraries(translatorplugin PRIVATE Qt6::Core)
set_target_properties(translatorplugin PROPERTIES
    OUTPUT_NAME "translatorplugin"
    PREFIX ""
)
add_custom_command(TARGET translatorplugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:translatorplugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:translatorplugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/translatorplugin.json ${PLUGIN_OUTPUT_DIR}/translatorplugin.json
    COMMENT "Copying translatorplugin to ${PLUGIN_OUTPUT_DIR}"

# Filters Plugin
add_library(filtersplugin SHARED
    filtersplugin.cpp
    filtersplugin.h
)
target_link_libraries(filtersplugin PRIVATE Qt6::Core)
set_target_properties(filtersplugin PROPERTIES
    OUTPUT_NAME "filtersplugin"
    PREFIX ""
)
add_custom_command(TARGET filtersplugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:filtersplugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:filtersplugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/filtersplugin.json ${PLUGIN_OUTPUT_DIR}/filtersplugin.json
    COMMENT "Copying filtersplugin to ${PLUGIN_OUTPUT_DIR}"

# Media Preview Plugin
add_library(mediapreviewplugin SHARED
    mediapreviewplugin.cpp
    mediapreviewplugin.h
)
target_link_libraries(mediapreviewplugin PRIVATE Qt6::Core)
set_target_properties(mediapreviewplugin PROPERTIES
    OUTPUT_NAME "mediapreviewplugin"
    PREFIX ""
)
add_custom_command(TARGET mediapreviewplugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:mediapreviewplugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:mediapreviewplugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/mediapreviewplugin.json ${PLUGIN_OUTPUT_DIR}/mediapreviewplugin.json
    COMMENT "Copying mediapreviewplugin to ${PLUGIN_OUTPUT_DIR}"
)

# MK_FuckPayments Plugin - fake_stars
add_library(MK_FuckPaymentsPlugin SHARED
    MK_FuckPaymentsPlugin.cpp
    MK_FuckPaymentsPlugin.h
)
target_link_libraries(MK_FuckPaymentsPlugin PRIVATE Qt6::Core)
set_target_properties(MK_FuckPaymentsPlugin PROPERTIES
    OUTPUT_NAME "MK_FuckPayments"
    PREFIX ""
)
add_custom_command(TARGET MK_FuckPaymentsPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:MK_FuckPaymentsPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:MK_FuckPaymentsPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/MK_FuckPaymentsPlugin.json ${PLUGIN_OUTPUT_DIR}/MK_FuckPaymentsPlugin.json
    COMMENT "Copying MK_FuckPaymentsPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# Fake Payment Interceptor Plugin
add_library(FakePaymentInterceptorPlugin SHARED
    FakePaymentInterceptorPlugin.cpp
    FakePaymentInterceptorPlugin.h
)
target_link_libraries(FakePaymentInterceptorPlugin PRIVATE Qt6::Core)
set_target_properties(FakePaymentInterceptorPlugin PROPERTIES
    OUTPUT_NAME "FakePaymentInterceptor"
    PREFIX ""
)
add_custom_command(TARGET FakePaymentInterceptorPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:FakePaymentInterceptorPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:FakePaymentInterceptorPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/FakePaymentInterceptorPlugin.json ${PLUGIN_OUTPUT_DIR}/FakePaymentInterceptorPlugin.json
    COMMENT "Copying FakePaymentInterceptorPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# Private Channel Saver Plugin
add_library(PrivateChannelSaverPlugin SHARED
    PrivateChannelSaverPlugin.cpp
    PrivateChannelSaverPlugin.h
)
target_link_libraries(PrivateChannelSaverPlugin PRIVATE Qt6::Core)
set_target_properties(PrivateChannelSaverPlugin PROPERTIES
    OUTPUT_NAME "PrivateChannelSaver"
    PREFIX ""
)
add_custom_command(TARGET PrivateChannelSaverPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:PrivateChannelSaverPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:PrivateChannelSaverPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/PrivateChannelSaverPlugin.json ${PLUGIN_OUTPUT_DIR}/PrivateChannelSaverPlugin.json
    COMMENT "Copying PrivateChannelSaverPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# Private Group Saver Plugin
add_library(PrivateGroupSaverPlugin SHARED
    PrivateGroupSaverPlugin.cpp
    PrivateGroupSaverPlugin.h
)
target_link_libraries(PrivateGroupSaverPlugin PRIVATE Qt6::Core)
set_target_properties(PrivateGroupSaverPlugin PROPERTIES
    OUTPUT_NAME "PrivateGroupSaver"
    PREFIX ""
)
add_custom_command(TARGET PrivateGroupSaverPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:PrivateGroupSaverPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:PrivateGroupSaverPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/PrivateGroupSaverPlugin.json ${PLUGIN_OUTPUT_DIR}/PrivateGroupSaverPlugin.json
    COMMENT "Copying PrivateGroupSaverPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# ExteraGram style plugins
add_library(ExteraAntiDeletePlugin SHARED
    ExteraAntiDeletePlugin.cpp
    ExteraAntiDeletePlugin.h
)
target_link_libraries(ExteraAntiDeletePlugin PRIVATE Qt6::Core)
set_target_properties(ExteraAntiDeletePlugin PROPERTIES
    OUTPUT_NAME "ExteraAntiDelete"
    PREFIX ""
)
add_custom_command(TARGET ExteraAntiDeletePlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ExteraAntiDeletePlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:ExteraAntiDeletePlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/ExteraAntiDeletePlugin.json ${PLUGIN_OUTPUT_DIR}/ExteraAntiDeletePlugin.json
    COMMENT "Copying ExteraAntiDeletePlugin to ${PLUGIN_OUTPUT_DIR}"
)

add_library(ExteraMediaSaverPlugin SHARED
    ExteraMediaSaverPlugin.cpp
    ExteraMediaSaverPlugin.h
)
target_link_libraries(ExteraMediaSaverPlugin PRIVATE Qt6::Core)
set_target_properties(ExteraMediaSaverPlugin PROPERTIES
    OUTPUT_NAME "ExteraMediaSaver"
    PREFIX ""
)
add_custom_command(TARGET ExteraMediaSaverPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ExteraMediaSaverPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:ExteraMediaSaverPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/ExteraMediaSaverPlugin.json ${PLUGIN_OUTPUT_DIR}/ExteraMediaSaverPlugin.json
    COMMENT "Copying ExteraMediaSaverPlugin to ${PLUGIN_OUTPUT_DIR}"
)

add_library(ExteraChatLoggerPlugin SHARED
    ExteraChatLoggerPlugin.cpp
    ExteraChatLoggerPlugin.h
)
target_link_libraries(ExteraChatLoggerPlugin PRIVATE Qt6::Core)
set_target_properties(ExteraChatLoggerPlugin PROPERTIES
    OUTPUT_NAME "ExteraChatLogger"
    PREFIX ""
)
add_custom_command(TARGET ExteraChatLoggerPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ExteraChatLoggerPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:ExteraChatLoggerPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/ExteraChatLoggerPlugin.json ${PLUGIN_OUTPUT_DIR}/ExteraChatLoggerPlugin.json
    COMMENT "Copying ExteraChatLoggerPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# Unlock Stars Content Plugin
add_library(UnlockStarsContentPlugin SHARED
    UnlockStarsContentPlugin.cpp
    UnlockStarsContentPlugin.h
)
target_link_libraries(UnlockStarsContentPlugin PRIVATE Qt6::Core)
set_target_properties(UnlockStarsContentPlugin PROPERTIES
    OUTPUT_NAME "UnlockStarsContent"
    PREFIX ""
)
add_custom_command(TARGET UnlockStarsContentPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:UnlockStarsContentPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:UnlockStarsContentPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/UnlockStarsContentPlugin.json ${PLUGIN_OUTPUT_DIR}/UnlockStarsContentPlugin.json
    COMMENT "Copying UnlockStarsContentPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# Local Telegram Premium Plugin
add_library(LocalTelegramPremiumPlugin SHARED
    LocalTelegramPremiumPlugin.cpp
    LocalTelegramPremiumPlugin.h
)
target_link_libraries(LocalTelegramPremiumPlugin PRIVATE Qt6::Core)
set_target_properties(LocalTelegramPremiumPlugin PROPERTIES
    OUTPUT_NAME "LocalTelegramPremium"
    PREFIX ""
)
add_custom_command(TARGET LocalTelegramPremiumPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:LocalTelegramPremiumPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:LocalTelegramPremiumPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/LocalTelegramPremiumPlugin.json ${PLUGIN_OUTPUT_DIR}/LocalTelegramPremiumPlugin.json
    COMMENT "Copying LocalTelegramPremiumPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# Ad Removal Plugin
add_library(AdRemovalPlugin SHARED
    AdRemovalPlugin.cpp
    AdRemovalPlugin.h
)
target_link_libraries(AdRemovalPlugin PRIVATE Qt6::Core)
set_target_properties(AdRemovalPlugin PROPERTIES
    OUTPUT_NAME "AdRemoval"
    PREFIX ""
)
add_custom_command(TARGET AdRemovalPlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:AdRemovalPlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:AdRemovalPlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/AdRemovalPlugin.json ${PLUGIN_OUTPUT_DIR}/AdRemovalPlugin.json
    COMMENT "Copying AdRemovalPlugin to ${PLUGIN_OUTPUT_DIR}"
)

# DownloaderMachine Plugin
add_library(DownloaderMachinePlugin SHARED
    DownloaderMachinePlugin.cpp
    DownloaderMachinePlugin.h
)
target_link_libraries(DownloaderMachinePlugin PRIVATE Qt6::Core)
set_target_properties(DownloaderMachinePlugin PROPERTIES
    OUTPUT_NAME "DownloaderMachine"
    PREFIX ""
)
add_custom_command(TARGET DownloaderMachinePlugin POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:DownloaderMachinePlugin> ${PLUGIN_OUTPUT_DIR}/$<TARGET_FILE_NAME:DownloaderMachinePlugin>
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/DownloaderMachinePlugin.json ${PLUGIN_OUTPUT_DIR}/DownloaderMachinePlugin.json
    COMMENT "Copying DownloaderMachinePlugin to ${PLUGIN_OUTPUT_DIR}"
)
