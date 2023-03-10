#include "Window.h"

#include <SFML/Window/Event.hpp>

Window::Window(const std::string& name)
    : window(sf::VideoMode(1280, 720), name, sf::Style::Close) {
    window.setVerticalSyncEnabled(true);
}

auto Window::update() -> void {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

auto Window::beginDraw() -> void {
    window.clear();
}

auto Window::draw(const sf::Drawable& drawable) -> void {
    window.draw(drawable);
}

auto Window::endDraw() -> void {
    window.display();
}

auto Window::isOpen() const -> bool {
    return window.isOpen();
}

auto Window::getCenter() const -> sf::Vector2f {
    auto size = window.getSize();
    return sf::Vector2f{static_cast<float>(size.x) / 2.F, static_cast<float>(size.y) / 2.F};
}