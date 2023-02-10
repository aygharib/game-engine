#pragma once

#include "Window.h"

class Object;

class Component {
public:
    Component(Object* owner);

    virtual auto awake() -> void {}
    virtual auto start() -> void {}

    virtual auto update(float deltaTime) -> void {}
    virtual auto lateUpdate(float deltaTime) -> void {}
    virtual auto draw(Window& window) -> void {}

protected:
    Object* owner;
};