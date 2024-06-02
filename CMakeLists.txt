cmake_minimum_required(VERSION 3.27)

project(iterm2-retro)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)

include_directories(iterm2-retro
    "include"
    "base64/include"
    "qoixx/include"
    )

add_subdirectory(base64)

add_executable(iterm2-retro
    src/audio.cpp
    src/iterm_manager.cpp
    src/main.cpp
    src/input_keyboard.cpp
    src/input_gamepad.cpp
    )
set_property(TARGET iterm2-retro PROPERTY CXX_STANDARD 20)

target_link_libraries(iterm2-retro PRIVATE SDL3::SDL3)