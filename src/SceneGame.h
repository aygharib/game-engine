#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Scene.h"
#include "Input.h"
#include "WorkingDirectory.h"

class SceneGame : public Scene {
public:
    SceneGame(WorkingDirectory& workingDirectory);
    
    // Necessary to implement from base scene class
    auto onCreate() -> void override;
    auto onDestroy() -> void override;
    
    // Override empty behaviour from base scene class
    auto update(float deltaTime) -> void override;
    auto draw(Window& window) -> void override;
    auto processInput() -> void override;
    
private:
    sf::Texture cubeTexture;
    sf::Sprite cubeSprite;
    
    WorkingDirectory& workingDirectory;
    Input input;
};