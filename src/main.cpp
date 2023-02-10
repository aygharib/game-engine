#include "GameEngine.h"
#include "WorkingDirectory.h"

#include <memory>

auto main() -> int {
    GameEngine gameEngine;

    while (gameEngine.isRunning()) {
        gameEngine.captureInput();
        gameEngine.update();
        gameEngine.lateUpdate();
        gameEngine.draw();
        gameEngine.calculateDeltaTime();
    }

    return 0;
}