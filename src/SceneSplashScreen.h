#pragma once

#include <SFML/Graphics.hpp>

#include "SceneStateMachine.h"
#include "WorkingDirectory.h"

class SceneSplashScreen : public Scene {
public:
    SceneSplashScreen(WorkingDirectory& workingDir, SceneStateMachine& sceneStateMachine, Window& window);

    // Necessary to implement from base scene class
    auto onCreate() -> void override;
    auto onDestroy() -> void override;
    
    // Override empty behaviour from base scene class
    auto onActivate() -> void override;
    auto update(float deltaTime) -> void override;
    auto draw(Window& window) -> void override;
    
    // Member functions specific to this scene
    auto setSwitchToScene(unsigned int id) -> void;
    
private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;
    
    SceneStateMachine& sceneStateMachine;
    Window& window;
    WorkingDirectory& workingDirectory;
    
	// We want to show this scene for a set amount of time
    float showForSeconds;
	
	// How long the scene has currently been visible.
    float currentSeconds;

	// The state we want to transition to when this scenes time expires.
    unsigned int switchToState;
};