#include "C_KeyboardMovement.h"
#include "C_Animation.h"
#include "Object.h" // for foward-declaration

#include "SFML/System/Vector2.hpp"

C_KeyboardMovement::C_KeyboardMovement(Object* owner) : Component(owner) {}

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
        animation->setAnimationDirection(FacingDirection::Left);
    }
    else if (input->isKeyPressed(Input::KEY::RIGHT)) {
        move.x = moveSpeed;
        animation->setAnimationDirection(FacingDirection::Right);
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

auto C_KeyboardMovement::awake() -> void {
    animation = getOwner()->getComponent<C_Animation>();
}