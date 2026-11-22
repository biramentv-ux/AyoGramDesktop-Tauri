cmake_minimum_required(VERSION 3.16)  # Minimum required version of CMake
project(AyoGramDesktop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Enable automatic MOC, RCC, and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Create executable
add_executable(${PROJECT_NAME}
    main.cpp
    mainwindow.cpp
    pluginmanager.cpp
    ayu_settings.cpp
    ayu_translator.cpp
    login.cpp
    login.h
    telegramclient.cpp
    telegramclient.h
)

# Link Qt libraries
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)

# Set the executable as the target for the project
set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Add translations
qt6_add_translation(QM_FILES translations/ayu_bg.ts)
add_custom_target(translations DEPENDS ${QM_FILES})

# Install translations
install(DIRECTORY translations DESTINATION ${CMAKE_INSTALL_PREFIX})

# Add the translations target to the build
add_dependencies(${PROJECT_NAME} translations)

# Post-build copy translations to Release/translations
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/translations
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${QM_FILES} ${CMAKE_BINARY_DIR}/translations/
    COMMENT "Copying translations to ${CMAKE_BINARY_DIR}/translations"
)

# Post-build copy portable config and settings
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/ayu_settings.json ${CMAKE_BINARY_DIR}/
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/portable.ini ${CMAKE_BINARY_DIR}/
    COMMENT "Copying portable config and settings to ${CMAKE_BINARY_DIR}"
)

# Post-build ensure plugins folder and copy README
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/plugins
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/README_PORTABLE.txt ${CMAKE_BINARY_DIR}/plugins/
    COMMENT "Copying README_PORTABLE to ${CMAKE_BINARY_DIR}/plugins"
)

# Add plugins subdirectory
add_subdirectory(plugins)
