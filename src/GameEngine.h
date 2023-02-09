#pragma once

#include "Window.h"

class GameEngine {
public:
    GameEngine();

    auto update() -> void;
    auto lateUpdate() -> void;
    auto draw() -> void;

    [[nodiscard]] auto isRunning() const -> bool;
private:
    Window window;
};