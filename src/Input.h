#pragma once

#include "Bitmask.h"
class Input {
public:
    enum class KEY {
        NONE = 0,
        LEFT = 1,
        RIGHT = 2,
        UP = 3,
        DOWN = 4,
        ESC = 5
    };

    auto update() -> void;

    auto isKeyPressed(KEY keycode) -> bool; // Returns true if the key is pressed
    auto isKeyDown(KEY keycode) -> bool; // Returns true if the key was just pressed
    auto isKeyUp(KEY keycode) -> bool; // Returns true if the key was just released
private:
    Bitmask currentFrameKeys;
    Bitmask previousFrameKeys;
};