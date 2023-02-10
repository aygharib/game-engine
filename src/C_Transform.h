#pragma once

#include "Component.h"
#include "SFML/System/Vector2.hpp"

class C_Transform : public Component {
public:
    C_Transform(Object* owner);

    auto setPosition(float x, float y) -> void;
    auto setPosition(const sf::Vector2f& pos) -> void;
    
    auto addPosition(float x, float y) -> void;
    auto addPosition(sf::Vector2f pos) -> void;

    auto setX(float x) -> void;
    auto setY(float y) -> void;

    auto addX(float x) -> void;
    auto addY(float y) -> void;

    [[nodiscard]] auto getPosition() const -> const sf::Vector2f&;

private:
    sf::Vector2f position;
};