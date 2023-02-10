#include "C_KeyboardMovement.h"
#include "Object.h" // for foward-declaration

#include "SFML/System/Vector2.hpp"

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner), moveSpeed(100.F), input(nullptr) {}

auto C_KeyboardMovement::setInput(Input* input) -> void {
    this->input = input;
}

auto C_KeyboardMovement::setMovementSpeed(float moveSpeed) -> void {
    this->moveSpeed = moveSpeed;
}

auto C_KeyboardMovement::update(float deltaTime) -> void {
    if (input == nullptr) {
        return;
    }

    sf::Vector2f move;

    if (input->isKeyPressed(Input::KEY::LEFT)) {
        move.x = -moveSpeed;
    }
    else if (input->isKeyPressed(Input::KEY::RIGHT)) {
        move.x = moveSpeed;
    } 

    if (input->isKeyPressed(Input::KEY::UP)) {
        move.y = -moveSpeed;
    }
    else if (input->isKeyPressed(Input::KEY::DOWN)) {
        move.y = moveSpeed;
    }

    auto xFrameMove = move.x * deltaTime;
    auto yFrameMove = move.y * deltaTime;

    getOwner()->transform->addPosition(xFrameMove, yFrameMove);
}