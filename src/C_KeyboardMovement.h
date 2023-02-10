#pragma once

#include "Component.h"
#include "Input.h"

class C_KeyboardMovement : public Component {
public:
    C_KeyboardMovement(Object* owner);

    auto setInput(Input* input) -> void;
    auto setMovementSpeed(float moveSpeed) -> void;

    // Override update to handle keyboard input
    auto update(float deltaTime) -> void override;

private:
    float moveSpeed;
    Input* input;
};