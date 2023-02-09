#include "GameEngine.h"

GameEngine::GameEngine() : window("Game Engine"), deltaTime(clock.restart().asSeconds()) {
    cubeTexture.loadFromFile("./resources/textures/cube.png");
    cubeSprite.setTexture(cubeTexture);
}

auto GameEngine::update() -> void {
    window.update();

    const auto& spritePosition = cubeSprite.getPosition();
    const auto pixelsToMovePerSecond = 100;
    const auto frameMovement = pixelsToMovePerSecond * deltaTime;
    cubeSprite.setPosition(spritePosition.x + frameMovement, spritePosition.y);
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