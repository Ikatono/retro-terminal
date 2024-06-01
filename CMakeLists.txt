cmake_minimum_required(VERSION 3.27)

project(iterm2-retro)
find_package(SDL3 REQUIRED)

include_directories(iterm2-retro
    "include"
    "base64/include"
    "qoixx/include"
    )

add_subdirectory(base64)
# add_subdirectory(qoixx)

add_executable(iterm2-retro
    src/audio.cpp
    src/iterm_manager.cpp
    src/main.cpp
    src/input_keyboard.cpp
    )
set_property(TARGET iterm2-retro PROPERTY CXX_STANDARD 20)
target_link_libraries(iterm2-retro
    )
