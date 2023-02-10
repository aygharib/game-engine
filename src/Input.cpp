#include "Input.h"

#include <SFML/Window/Keyboard.hpp>

auto Input::update() -> void {
    previousFrameKeys.setMask(currentFrameKeys);

    currentFrameKeys.setBit((int)KEY::LEFT,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));
    
    currentFrameKeys.setBit((int)KEY::RIGHT,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));
    
    currentFrameKeys.setBit((int)KEY::UP,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));
  
    currentFrameKeys.setBit((int)KEY::DOWN,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));
  
    currentFrameKeys.setBit((int)KEY::ESC, 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}

auto Input::isKeyPressed(KEY keycode) -> bool {
    return currentFrameKeys.getBit(static_cast<int>(keycode));
}

auto Input::isKeyDown(KEY keycode) -> bool {
    bool lastFrame = previousFrameKeys.getBit(static_cast<int>(keycode));
    bool thisFrame = currentFrameKeys.getBit(static_cast<int>(keycode));
    
    return thisFrame && !lastFrame;
}

auto Input::isKeyUp(KEY keycode) -> bool {
    bool lastFrame = previousFrameKeys.getBit(static_cast<int>(keycode));
    bool thisFrame = currentFrameKeys.getBit(static_cast<int>(keycode));
    
    return !thisFrame && lastFrame;
}