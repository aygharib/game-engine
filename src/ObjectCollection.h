#pragma once

#include "Object.h"

#include <memory>
#include <vector>

class ObjectCollection {
public:
    auto add(std::shared_ptr<Object> object) -> void;
    
    auto update(float deltaTime) -> void;
    auto lateUpdate(float deltaTime) -> void;
    auto draw(Window& window) -> void;
    
    auto processNewObjects() -> void;
    auto processRemovals() -> void;

private:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Object>> newObjects;
};