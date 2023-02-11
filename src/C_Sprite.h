#pragma once

#include "Component.h"

#include "ResourceAllocator.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class C_Sprite : public Component {
public:
    C_Sprite(Object* owner);

    // Loads a sprite from a file
    auto load(const std::string& filePath) -> void;

    // Override lateUpdate member function to update sprite position
    auto lateUpdate(float deltaTime) -> void override;

    // Override draw member function to draw sprite
    auto draw(Window& window) -> void override;

    // We add a new overloaded load method that accepts a texture id
    auto load(int id) -> void;

    auto setTextureAllocator(ResourceAllocator<sf::Texture>* allocator) -> void;

    auto setTextureRect(int x, int y, int width, int height) -> void;
    auto setTextureRect(const sf::IntRect& rect) -> void;

private:
    sf::Texture texture;
    ResourceAllocator<sf::Texture>* allocator;
    sf::Sprite sprite;
    int currentTextureId{-1}; // keep track of current set texture
};