#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

#include "Input.h"
#include "SceneStateMachine.h"
#include "Window.h"
#include "WorkingDirectory.h"

class GameEngine {
public:
    GameEngine();

    auto update() -> void;
    auto lateUpdate() -> void;
    auto draw() -> void;

    auto calculateDeltaTime() -> void;

    [[nodiscard]] auto isRunning() const -> bool;

    auto captureInput() -> void;
private:
    WorkingDirectory workingDirectory;
    Window window;
    sf::Clock clock;
    float deltaTime;

    SceneStateMachine sceneStateMachine;
};