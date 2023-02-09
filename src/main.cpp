#include "GameEngine.h"

auto main() -> int {
    GameEngine gameEngine;

    while (gameEngine.isRunning()) {
        gameEngine.update();
        gameEngine.lateUpdate();
        gameEngine.draw();
        gameEngine.calculateDeltaTime();
    }

    return 0;
}