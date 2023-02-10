#include "SceneGame.h"

#include "Object.h"
#include "C_KeyboardMovement.h"
#include "C_Sprite.h"
#include <memory>

SceneGame::SceneGame(WorkingDirectory& workingDirectory) : workingDirectory(workingDirectory) {}

auto SceneGame::onCreate() -> void {
    player = std::make_shared<Object>();

    auto sprite = player->addComponent<C_Sprite>();
    sprite->load(workingDirectory.get() + "cube.png");

    auto movement = player->addComponent<C_KeyboardMovement>();
    movement->setInput(&input);
}

auto SceneGame::onDestroy() -> void {
    
}

auto SceneGame::processInput() -> void {
    input.update();
}

auto SceneGame::update(float deltaTime) -> void {
    player->update(deltaTime);
}

auto SceneGame::lateUpdate(float deltaTime) -> void {
    player->lateUpdate(deltaTime);
}

auto SceneGame::draw(Window& window) -> void {
    player->draw(window);
}