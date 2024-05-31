#include "fpng.h"

#include <stdint.h>
#include <vector>
#include <array>

// using raw_frame_t = void*

struct raw_frame_t
{
    void* data;
    uint32_t width;
    uint32_t height;

};

struct frame_size_t
{
    uint32_t width;
    uint32_t height;
};
static frame_size_t config;

void set_frame_size(frame_size_t size)
{
    config = size;
}

std::vector<char> create_frame(raw_frame_t raw_frame)
{
    const char PREFIX[] = "\033[File=Inline=1;Height=";
    std::array<char, 4> height;
    std::vector<uint8_t> img;

    fpng::fpng_encode_image_to_memory(raw_frame.data, raw_frame.width, raw_frame.height, 3, img);

    std::vector<char> packed;
    packed.resize(sizeof(PREFIX) + height.size());

    return packed;
}