#include "iterm_manager.h"
#include "base64.hpp"
#include "qoixx.hpp"

std::vector<char> create_frame(raw_frame_t raw_frame)
{
    const char PREFIX[] = "\033[File=Inline=1;Height=";
    std::array<char, 4> height;
    std::vector<uint8_t> img;
    

    std::vector<char> packed;
    packed.resize(sizeof(PREFIX) + height.size());

    return packed;
}