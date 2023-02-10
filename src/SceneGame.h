#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <memory>

#include "Object.h"
#include "Component.h"
#include "ResourceAllocator.h"
#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"

class SceneGame : public Scene {
public:
    SceneGame(WorkingDirectory& workingDirectory, ResourceAllocator<sf::Texture>& textureAllocator);
    
    // Necessary to implement from base scene class
    auto onCreate() -> void override;
    auto onDestroy() -> void override;
    
    // Override empty behaviour from base scene class
    auto update(float deltaTime) -> void override;
    auto lateUpdate(float deltaTime) -> void override;
    auto draw(Window& window) -> void override;
    auto processInput() -> void override;
    
private:
    std::shared_ptr<Object> player;
    
    WorkingDirectory& workingDirectory;
    ResourceAllocator<sf::Texture>& textureAllocator;
    Input input;
};