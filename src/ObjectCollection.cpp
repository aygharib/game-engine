#include "ObjectCollection.h"

auto ObjectCollection::add(std::shared_ptr<Object> object) -> void {
    newObjects.push_back(object);
}

auto ObjectCollection::update(float deltaTime) -> void {
    for (auto& object : objects) {
        object->update(deltaTime);
    }
}

auto ObjectCollection::lateUpdate(float deltaTime) -> void {
    for (auto& object : objects) {
        object->lateUpdate(deltaTime);
    }
}

auto ObjectCollection::draw(Window& window) -> void {
    for (auto& object : objects) {
        object->draw(window);
    }
}

auto ObjectCollection::processNewObjects() -> void {
    if (!newObjects.empty()) {
        for (const auto& object : newObjects) {
            object->awake();
        }

        for (const auto& object : newObjects) {
            object->start();
        }

        objects.assign(newObjects.begin(), newObjects.end());

        newObjects.clear();
    }
}

auto ObjectCollection::processRemovals() -> void {
    auto objIterator = objects.begin();
    while (objIterator != objects.end()) {
        auto obj = **objIterator;
        
        if (obj.isQueuedForRemoval()) {
            objIterator = objects.erase(objIterator);
        }
        else {
            ++objIterator;
        }
    }
}