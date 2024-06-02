#include "input_gamepad.h"

#include <algorithm>
#include <iostream>

namespace Gamepad
{

    int init()
    {
        auto ret = SDL_InitSubSystem(SDL_INIT_GAMEPAD);
        if (ret)
        {
            std::cout << "Failed to initialize gamepad subsystem: " << SDL_GetError();
            return ret;
        }
        else
        {
            std::cout << "Successfully initialized gamepad subsystem" << std::endl;
        }
        SDL_SetGamepadEventsEnabled(SDL_TRUE);
        return 0;
    }

    SDL_Gamepad* getAnyGamepad()
    {
        int count = 0;
        SDL_JoystickID* const ids = SDL_GetJoysticks(&count);
        for (int i = 0; i < count; i++)
        {
            const auto& id = ids[i];
            if (SDL_IsGamepad(id))
            {
                auto gamepad = SDL_OpenGamepad(id);
                if (gamepad)
                {
                    return gamepad;
                }
            }
        }
        return nullptr;   
    }
}
