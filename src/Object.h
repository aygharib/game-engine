#pragma once

#include "Component.h"
#include "C_Transform.h"
#include "Window.h"

#include <memory>

class Object {
public:
    Object();

    // Awake is called when the object is created
    // Use to ensure required components are present
    auto awake() -> void;

    // Start is called after awake method
    // Use to initialize variables
    auto start() -> void;

    auto update(float deltaTime) -> void;
    auto lateUpdate(float deltaTime) -> void;
    auto draw(Window& window) -> void;

    template<typename T>
    auto addComponent() -> std::shared_ptr<T> {
		// This ensures that we only try to add a class the derives 
		// from Component. This is tested at compile time.
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
        
        // Check that we don't already have a component of this type.
        for (auto& existingComponent : components) {
			// Currently we prevent adding the same component twice. 
			// This may be something we will change in future.
            if (std::dynamic_pointer_cast<T>(existingComponent)) {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }
        
        // The object does not have this component so we create it and 
		// add it to our list.
        std::shared_ptr<T> newComponent = std::make_shared<T>(this);
        components.push_back(newComponent);
        
        return newComponent;
    }

    template<typename T>
    auto getComponent() -> std::shared_ptr<T> {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        // Check that we don’t already have a component of this type.
        for (auto& existingComponent : components) {
            if (std::dynamic_pointer_cast<T>(existingComponent)) {
                return std::dynamic_pointer_cast<T>(existingComponent);
            }
        }
        
        return nullptr;
    }

    std::shared_ptr<C_Transform> transform;

private:
    std::vector<std::shared_ptr<Component>> components;
};