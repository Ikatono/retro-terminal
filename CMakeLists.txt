cmake_minimum_required(VERSION 3.27)

project(iterm2-retro)

include_directories(iterm2-retro
    "include"
    "base64/include"
    "qoixx/include"
    "base64/include"
    )

add_subdirectory(SDL)
add_subdirectory(base64)
# add_subdirectory(qoixx)

add_executable(iterm2-retro
    src/audio.cpp
    src/iterm_manager.cpp
    src/main.cpp
    )
set_property(TARGET iterm2-retro PROPERTY CXX_STANDARD 20)
target_link_libraries(iterm2-retro
    )
