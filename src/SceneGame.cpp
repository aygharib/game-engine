#include "SceneGame.h"

#include "Object.h"
#include "C_Sprite.h"
#include <memory>

SceneGame::SceneGame(WorkingDirectory& workingDirectory) : workingDirectory(workingDirectory) {}

auto SceneGame::onCreate() -> void {
    player = std::make_shared<Object>();

    auto sprite = player->addComponent<C_Sprite>();
    sprite->load(workingDirectory.get() + "cube.png");
}

auto SceneGame::onDestroy() -> void {
    
}

auto SceneGame::processInput() -> void {
    input.update();
}

auto SceneGame::update(float deltaTime) -> void {}

auto SceneGame::draw(Window& window) -> void {
    player->draw(window);
}