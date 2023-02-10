#pragma once

#include "Window.h"

class Scene {
public:
	// Called when scene initially created. Called once.
    virtual auto onCreate() -> void = 0; 
	
	// Called when scene destroyed. Called at most once (if a scene 
	// is not removed from the game, this will never be called).
    virtual auto onDestroy() -> void = 0; 
    
	// Called whenever a scene is transitioned into. Can be 
	// called many times in a typical game cycle.
    virtual auto onActivate() -> void {}; 
	
	// Called whenever a transition out of a scene occurs. 
	// Can be called many times in a typical game cycle.
    virtual auto onDeactivate() -> void {};
	
    // The below functions can be overridden as necessary in our scenes.
    virtual auto processInput() -> void {};
    virtual auto update(float deltaTime) -> void {};
    virtual auto lateUpdate(float deltaTime) -> void {};
    virtual auto draw(Window& window) -> void {};
};