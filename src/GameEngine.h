#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

#include "Window.h"

class GameEngine {
public:
    GameEngine();

    auto update() -> void;
    auto lateUpdate() -> void;
    auto draw() -> void;

    auto calculateDeltaTime() -> void;

    [[nodiscard]] auto isRunning() const -> bool;
private:
    Window window;
    sf::Clock clock;
    float deltaTime;

    sf::Texture cubeTexture;
    sf::Sprite cubeSprite;
};