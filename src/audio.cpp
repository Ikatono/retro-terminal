#include "audio.h"

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_audio.h>

#include <iostream>

namespace Audio
{

int init()
{
    auto ret = SDL_InitSubSystem(SDL_INIT_AUDIO);
    if (ret)
    {
        std::cout << "Failed to initialize audio subsystem: " << SDL_GetError();
    }
    else
    {
        std::cout << "Successfully initialized audio subsystem" << std::endl;
    }
    return ret;
}

int getSampleAudio(AudioFile* file)
{
    return SDL_LoadWAV("music.wav", &file->spec,
        &file->audio_buf, &file->audio_len);
}

}