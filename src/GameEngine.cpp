#include "GameEngine.h"
#include "SFML/System/Vector2.hpp"

GameEngine::GameEngine() : window("Game Engine"), deltaTime(clock.restart().asSeconds()) {
    cubeTexture.loadFromFile("./resources/textures/cube.png");
    cubeSprite.setTexture(cubeTexture);
}

auto GameEngine::update() -> void {
    window.update();

    const auto& spritePosition = cubeSprite.getPosition();
    const auto moveSpeed = 100;

    sf::Vector2f move{0.F, 0.F};

    if(input.isKeyPressed(Input::Key::Left)) {
        move.x = -moveSpeed;
    }
    else if(input.isKeyPressed(Input::Key::Right)) {
        move.x = moveSpeed;
    }
    
    int yMove = 0;
    if(input.isKeyPressed(Input::Key::Up)) {
        move.y = -moveSpeed;
    }
    else if(input.isKeyPressed(Input::Key::Down)) {
        move.y = moveSpeed;
    }

    sf::Vector2f frameMove = {move.x * deltaTime, move.y * deltaTime};

    cubeSprite.setPosition(spritePosition.x + frameMove.x, spritePosition.y + frameMove.y);
}

auto GameEngine::lateUpdate() -> void {}

auto GameEngine::draw() -> void {
    window.beginDraw();
    window.draw(cubeSprite);
    window.endDraw();
}

auto GameEngine::calculateDeltaTime() -> void {
    deltaTime = clock.restart().asSeconds();
}

auto GameEngine::isRunning() const -> bool {
    return window.isOpen();
}

auto GameEngine::captureInput() -> void {
    input.update();
}