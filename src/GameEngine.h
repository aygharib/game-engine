#pragma once

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
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

    sf::Texture cubeTexture;
    sf::Sprite cubeSprite;
};