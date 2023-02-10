#pragma once

#include "Bitmask.h"
class Input {
public:
    enum class Key {
        None = 0,
        Left = 1,
        Right = 2,
        Up = 3,
        Down = 4,
        Esc = 5
    };

    auto update() -> void;

    auto isKeyPressed(Key keycode) -> bool; // Returns true if the key is pressed
    auto isKeyDown(Key keycode) -> bool; // Returns true if the key was just pressed
    auto isKeyUp(Key keycode) -> bool; // Returns true if the key was just released
private:
    Bitmask currentFrameKeys;
    Bitmask previousFrameKeys;
};