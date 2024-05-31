cmake_minimum_required(VERSION 3.27)

project(iterm2-retro)


include_directories(iterm2-retro
    "include"
    # "fpng/src"
    "base64/include"
    "qoixx/include"
    )

add_subdirectory(
    fpng
    base64
    )

add_executable(iterm2-retro
    src/audio.cpp
    src/miniaudio.cpp
    src/iterm_manager.cpp
    src/main.cpp
    # fpng/src/fpng.cpp
    )
set_property(TARGET iterm2-retro PROPERTY CXX_STANDARD 20)
target_link_libraries(iterm2-retro
    fpng_test
    )
