cmake_minimum_required(VERSION 3.10)

add_library(LocalTelegramPremiumPlugin SHARED
    LocalTelegramPremiumPlugin.cpp
    LocalTelegramPremiumPlugin.h
)

target_include_directories(LocalTelegramPremiumPlugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(LocalTelegramPremiumPlugin PROPERTIES
    PREFIX ""
    SUFFIX ".dll"
)

install(TARGETS LocalTelegramPremiumPlugin
    LIBRARY DESTINATION plugins
)