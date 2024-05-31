#ifndef H_E4B0E8F9E55047EAB5D036235B3A0AAC
#define H_E4B0E8F9E55047EAB5D036235B3A0AAC

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

std::vector<char> create_frame(raw_frame_t raw_frame);

#endif //H_E4B0E8F9E55047EAB5D036235B3A0AAC
