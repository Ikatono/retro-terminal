#ifndef H_88f7ae7359d8467cb76761132df1590f
#define H_88f7ae7359d8467cb76761132df1590f

#include <SDL3/SDL.h>
#include <SDL3/SDL_joystick.h>
#include <SDL3/SDL_gamepad.h>
#include <vector>

namespace Gamepad
{

int init();
SDL_Gamepad* getAnyGamepad();
template <typename T>
const char* getButtonName(T button)
{
    switch (static_cast<uint8_t>(button))
    {
        case SDL_GAMEPAD_BUTTON_SOUTH:
            return "A";
        case SDL_GAMEPAD_BUTTON_EAST:
            return "B";
        case SDL_GAMEPAD_BUTTON_WEST:
            return "X";
        case SDL_GAMEPAD_BUTTON_NORTH:
            return "Y";
        default:
            return "Unknown";
    }
}

}

#endif //H_88f7ae7359d8467cb76761132df1590f