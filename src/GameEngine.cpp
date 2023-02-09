#include "GameEngine.h"

GameEngine::GameEngine() : window("Game Engine") {
    cubeTexture.loadFromFile("./resources/textures/cube.png");
    cubeSprite.setTexture(cubeTexture);
}

auto GameEngine::update() -> void {
    window.update();
}

auto GameEngine::lateUpdate() -> void {}

auto GameEngine::draw() -> void {
    window.beginDraw();
    window.draw(cubeSprite);
    window.endDraw();
}

auto GameEngine::isRunning() const -> bool {
    return window.isOpen();
}