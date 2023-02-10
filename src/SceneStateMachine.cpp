#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine() : scenes(0), currentScene(nullptr), insertedSceneID(0) {}

void SceneStateMachine::processInput() {
    if(currentScene) {
        currentScene->processInput();
    }
}

void SceneStateMachine::update(float deltaTime) {
    if(currentScene) {
        currentScene->update(deltaTime);
    }
}

void SceneStateMachine::lateUpdate(float deltaTime) {
    if(currentScene) {
        currentScene->lateUpdate(deltaTime);
    }
}

void SceneStateMachine::draw(Window& window) {
    if(currentScene) {
        currentScene->draw(window);
    }
}

auto SceneStateMachine::add(const std::shared_ptr<Scene>& scene) -> unsigned int {
    auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
    
    insertedSceneID++;

    inserted.first->second->onCreate();
    
    return insertedSceneID - 1;
}

auto SceneStateMachine::switchTo(unsigned int id) -> void {
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (currentScene) {
			// If we have a current scene, we call its OnDeactivate method.
            currentScene->onDeactivate(); 
        }
        
		// Setting the current scene ensures that it is updated and drawn.
        currentScene = it->second; 
        
        currentScene->onActivate();
    }
}

auto SceneStateMachine::remove(unsigned int id) -> void {
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (currentScene == it->second) {
			// If the scene we are removing is the current scene, 
			// we also want to set that to a null pointer so the scene 
			// is no longer updated.
            currentScene = nullptr;
        }
        
		// We make sure to call the OnDestroy method 
		// of the scene we are removing.
        it->second->onDestroy(); 
        
        scenes.erase(it);
    }
}