#include "SceneGame.h"

#include "Animation.h"
#include "C_Animation.h"
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

    auto movement = player->addComponent<C_KeyboardMovement>();
    movement->setInput(&input);

    auto animation = player->addComponent<C_Animation>();
    
    auto cubeTextureId = textureAllocator.add(workingDirectory.get() + "cube.png");

    const auto frameWidth = 50;
    const auto frameHeight = 50;

    auto idleAnimation = std::make_shared<Animation>(FacingDirection::Right);

    // How long we want to show each frame
    const auto idleAnimationFrameSeconds = 0.2F;
    idleAnimation->addFrame(cubeTextureId, 0, 0, 50, 50, idleAnimationFrameSeconds);
    idleAnimation->addFrame(cubeTextureId, 50, 0, 50, 50, idleAnimationFrameSeconds);

    animation->addAnimation(AnimationState::Idle, idleAnimation);

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