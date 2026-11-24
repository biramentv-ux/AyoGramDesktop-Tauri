add_library(LocalTelegramPremiumPlugin STATIC LocalTelegramPremiumPlugin.cpp)
target_include_directories(LocalTelegramPremiumPlugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS LocalTelegramPremiumPlugin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin)