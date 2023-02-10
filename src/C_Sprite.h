#include "Component.h"

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

private:
    sf::Texture texture;
    sf::Sprite sprite;
};