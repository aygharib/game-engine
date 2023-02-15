#pragma once

#include "C_Animation.h"
#include "Component.h"
#include "Input.h"
#include <memory>

class C_KeyboardMovement : public Component {
public:
    C_KeyboardMovement(Object* owner);

    auto setInput(Input* input) -> void;
    auto setMovementSpeed(float moveSpeed) -> void;

    // Override update to handle keyboard input
    auto update(float deltaTime) -> void override;
    auto awake() -> void override;

private:
    float moveSpeed{200.F};
    Input* input{nullptr};

    std::shared_ptr<C_Animation> animation;
};