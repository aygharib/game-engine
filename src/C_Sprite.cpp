#include "C_Sprite.h"
#include "Object.h" // for foward-declaration

C_Sprite::C_Sprite(Object* owner) : Component(owner) {}

auto C_Sprite::setTextureAllocator(ResourceAllocator<sf::Texture>* allocator) -> void {
    this->allocator = allocator;
}

auto C_Sprite::load(int id) -> void {
    if (id >= 0) {
        auto texture = allocator->get(id);
        sprite.setTexture(*texture);
    }
}

auto C_Sprite::load(const std::string& filePath) -> void {
    if (allocator != nullptr) {
        auto textureId = allocator->add(filePath);

        if (textureId >= 0) {
            auto texture = allocator->get(textureId);
            sprite.setTexture(*texture);
        }
    }
}

auto C_Sprite::lateUpdate(float /*deltaTime*/) -> void {
    sprite.setPosition(getOwner()->transform->getPosition());
}

auto C_Sprite::draw(Window& window) -> void {
    window.draw(sprite);
}