#include "Input.h"

#include <SFML/Window/Keyboard.hpp>

auto Input::update() -> void {
    previousFrameKeys.setMask(currentFrameKeys);

    currentFrameKeys.setBit((int)Key::Left,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));
    
    currentFrameKeys.setBit((int)Key::Right,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));
    
    currentFrameKeys.setBit((int)Key::Up,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));
  
    currentFrameKeys.setBit((int)Key::Down,
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || 
						 (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));
  
    currentFrameKeys.setBit((int)Key::Esc, 
		sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
}

auto Input::isKeyPressed(Key keycode) -> bool {
    return currentFrameKeys.getBit(static_cast<int>(keycode));
}

auto Input::isKeyDown(Key keycode) -> bool {
    bool lastFrame = previousFrameKeys.getBit(static_cast<int>(keycode));
    bool thisFrame = currentFrameKeys.getBit(static_cast<int>(keycode));
    
    return thisFrame && !lastFrame;
}

auto Input::isKeyUp(Key keycode) -> bool {
    bool lastFrame = previousFrameKeys.getBit(static_cast<int>(keycode));
    bool thisFrame = currentFrameKeys.getBit(static_cast<int>(keycode));
    
    return !thisFrame && lastFrame;
}