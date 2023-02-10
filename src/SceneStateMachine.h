#pragma once

#include "Scene.h"
#include "Window.h"

#include <memory>
#include <unordered_map>

class SceneStateMachine {
public:
    SceneStateMachine();

    // ProcessInput, Update, LateUpdate, and Draw will simply be 
	// pass through methods. They will call the correspondingly 
	// named methods of the active scene.
    auto processInput() -> void;
    auto update(float deltaTime) -> void;
    auto lateUpdate(float deltaTime) -> void;
    auto draw(Window& window) -> void;
    
	// Adds a scene to the state machine and returns the id of that scene.
    auto add(const std::shared_ptr<Scene>& scene) -> unsigned int;
	
	// Transitions to scene with specified id.
    auto switchTo(unsigned int id) -> void;
	
	// Removes scene from state machine.
    auto remove(unsigned int id) -> void;

private:
	// Stores all of the scenes associated with this state machine.
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
	
	// Stores a pointer to the current scene. Used when drawing/updating.
    std::shared_ptr<Scene> currentScene;
	
	// Stores our current scene id. This is incremented whenever 
	// a scene is added.
    unsigned int insertedSceneID;
};