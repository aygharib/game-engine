#include "Object.h"
#include "C_Transform.h"
#include <memory>

Object::Object() {
    transform = addComponent<C_Transform>();
}

auto Object::awake() -> void {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->awake();
    }
}

auto Object::start() -> void {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->start();
    }
}

auto Object::update(float deltaTime) -> void {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->update(deltaTime);
    }
}

auto Object::lateUpdate(float deltaTime) -> void {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->lateUpdate(deltaTime);
    }
}

auto Object::draw(Window& window) -> void {
    for (int i = components.size() - 1; i >= 0; i--) {
        components[i]->draw(window);
    }
}