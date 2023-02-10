#include "C_Sprite.h"
#include "Component.h"

C_Sprite::C_Sprite(Object* owner) : Component(owner) {}

auto C_Sprite::load(const std::string& filePath) -> void {
    texture.loadFromFile(filePath);
    sprite.setTexture(texture);
}

auto C_Sprite::draw(Window& window) -> void {
    window.draw(sprite);
}