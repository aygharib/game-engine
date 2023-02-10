#include "C_Transform.h"
#include "Component.h"

C_Transform::C_Transform(Object* owner) : Component(owner) {}

auto C_Transform::setPosition(float x, float y) -> void {
    position.x = x;
    position.y = y;
}

auto C_Transform::setPosition(const sf::Vector2f& pos) -> void {
    position = pos;
}

auto C_Transform::addPosition(float x, float y) -> void {
    position.x += x;
    position.y += y;
}

auto C_Transform::addPosition(sf::Vector2f pos) -> void {
    position += pos;
}

auto C_Transform::setX(float x) -> void {
    position.x = x;
}

auto C_Transform::setY(float y) -> void {
    position.y = y;
}

auto C_Transform::addX(float x) -> void {
    position.x += x;
}

auto C_Transform::addY(float y) -> void {
    position.y += y;
}

auto C_Transform::getPosition() const -> const sf::Vector2f& {
    return position;
}