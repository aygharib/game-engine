#include "GameEngine.h"

#include <utility>

#include "SceneGame.h"
#include "SceneSplashScreen.h"
#include "WorkingDirectory.h"

GameEngine::GameEngine() : window("Game Engine") {
    const auto splashScreen = std::make_shared<SceneSplashScreen>(workingDirectory, sceneStateMachine, window, textureAllocator);
    const auto gameScene = std::make_shared<SceneGame>(workingDirectory, textureAllocator);
       
    auto splashScreenID = sceneStateMachine.add(splashScreen);
    auto gameSceneID = sceneStateMachine.add(gameScene);
    
    splashScreen->setSwitchToScene(gameSceneID);
    
    sceneStateMachine.switchTo(splashScreenID);
    
    deltaTime = clock.restart().asSeconds();
}

auto GameEngine::update() -> void {
    window.update();

    sceneStateMachine.update(deltaTime);
}

auto GameEngine::lateUpdate() -> void {
    sceneStateMachine.lateUpdate(deltaTime);
}

auto GameEngine::draw() -> void {
    window.beginDraw();
    sceneStateMachine.draw(window);
    window.endDraw();
}

auto GameEngine::calculateDeltaTime() -> void {
    deltaTime = clock.restart().asSeconds();
}

auto GameEngine::isRunning() const -> bool {
    return window.isOpen();
}

auto GameEngine::captureInput() -> void {
    sceneStateMachine.processInput();
}