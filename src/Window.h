#pragma once

#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Window {
public:
    Window(const std::string& name);

    auto update() -> void;

    auto beginDraw() -> void;
    auto draw(const sf::Drawable& drawable) -> void;
    auto endDraw() -> void;

    auto isOpen() const -> bool;
    auto getCenter() const -> sf::Vector2f;
private:
    sf::RenderWindow window;
};