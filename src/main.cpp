#define SDL_MAIN_NOIMPL
#include <SDL3/SDL.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_gamepad.h>
#include <SDL3/SDL_audio.h>

#include "input_gamepad.h"
#include "audio.h"

#include <iostream>

int main(int argc, char **argv)
{
    // if (SDL_Init(SDL_INIT_AUDIO))
    // {
    //     SDL_Quit();
    // }
    std::cout << "Starting Program" << std::endl;
    if (Gamepad::init())
    {
        std::cout << "Failed to init gamepad system" << std::endl;
        SDL_Quit();
        return -1;
    }
    std::cout << "Successful init" << std::endl;
    auto gamepad = Gamepad::getAnyGamepad();
    if (!gamepad)
    {
        std::cout << "Failed to initialize gamepad" << std::endl;
        SDL_Quit();
        return -1;
    }
    if (Audio::init())
    {
        std::cout << "Failed to init audiosystem: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }
    Audio::AudioFile file;
    if (Audio::getSampleAudio(&file))
    {
        std::cout << "Failed to initialize audio: " << SDL_GetError() << std::endl;
        return -1;
    }
    auto* const audioStream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_OUTPUT, &file.spec, nullptr, nullptr);
    if (!audioStream)
    {
        std::cout << "Failed to open audio device: " << SDL_GetError() << std::endl;
        return -1;
    }
    SDL_AudioSpec outSpec;
    int sampleFrames;
    if (SDL_GetAudioDeviceFormat(SDL_GetAudioStreamDevice(audioStream), &outSpec, &sampleFrames))
    {
        std::cout << "Failed to get audio device format: " << SDL_GetError() << std::endl;
        return -1;
    }
    if (SDL_PutAudioStreamData(audioStream, file.audio_buf, file.audio_len))
    {
        std::cout << "Failed to add audio to stream: " << SDL_GetError() << std::endl;
        return -1;
    }
    if (SDL_ResumeAudioDevice(SDL_GetAudioStreamDevice(audioStream)))
    {
        std::cout << "Failed to resume audio device: " << SDL_GetError() << std::endl;
    }
    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_GAMEPAD_BUTTON_DOWN)
            {
                SDL_GamepadButtonEvent& gbe = event.gbutton;
                std::cout << "Button pressed: " << Gamepad::getButtonName(gbe.button) << std::endl;
            }
            else if (event.type == SDL_EVENT_QUIT)
            {
                std::cout << "Received quit event" << std::endl;
                SDL_Quit();
                return -1;
            }
            SDL_Delay(1000 / 60);
        }
    }
}
