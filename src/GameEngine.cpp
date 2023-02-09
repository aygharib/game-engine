#include "GameEngine.h"

GameEngine::GameEngine() : window("Game Engine") {}

auto GameEngine::update() -> void {
    window.update();
}

auto GameEngine::lateUpdate() -> void {}

auto GameEngine::draw() -> void {
    window.beginDraw();
    // TODO: Add Draw code here
    window.endDraw();
}

auto GameEngine::isRunning() const -> bool {
    return window.isOpen();
}