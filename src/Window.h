#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include <SFML/Graphics.hpp>

class Window {
public:
    Window(const std::string& name);

    auto update() -> void;

    auto beginDraw() -> void;
    auto draw(const sf::Drawable& drawable) -> void;
    auto endDraw() -> void;

    auto isOpen() const -> bool;
private:
    sf::RenderWindow window;
};