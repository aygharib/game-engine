#include "SceneGame.h"

#include "Object.h"
#include "C_KeyboardMovement.h"
#include "C_Sprite.h"
#include <memory>

SceneGame::SceneGame(WorkingDirectory& workingDirectory, ResourceAllocator<sf::Texture>& textureAllocator)
    : workingDirectory(workingDirectory), textureAllocator(textureAllocator) {}

auto SceneGame::onCreate() -> void {
    auto player = std::make_shared<Object>();

    auto sprite = player->addComponent<C_Sprite>();
    sprite->setTextureAllocator(&textureAllocator);
    sprite->load(workingDirectory.get() + "cube.png");

    auto movement = player->addComponent<C_KeyboardMovement>();
    movement->setInput(&input);

    objects.add(player);
}

auto SceneGame::onDestroy() -> void {
    
}

auto SceneGame::processInput() -> void {
    input.update();
}

auto SceneGame::update(float deltaTime) -> void {
    objects.processRemovals();
    objects.processNewObjects();

    objects.update(deltaTime);
}

auto SceneGame::lateUpdate(float deltaTime) -> void {
    objects.lateUpdate(deltaTime);
}

auto SceneGame::draw(Window& window) -> void {
    objects.draw(window);
}