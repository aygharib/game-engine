#include "SceneGame.h"

SceneGame::SceneGame(WorkingDirectory& workingDirectory) : workingDirectory(workingDirectory) {}

auto SceneGame::onCreate() -> void {
    cubeTexture.loadFromFile(workingDirectory.get() + "cube.png");
    cubeSprite.setTexture(cubeTexture);
}

auto SceneGame::onDestroy() -> void {
    
}

auto SceneGame::processInput() -> void {
    input.update();
}

auto SceneGame::update(float deltaTime) -> void {
    const sf::Vector2f& spritePos = cubeSprite.getPosition();
    const int moveSpeed = 100;

    sf::Vector2f move{0.F, 0.F};

    if(input.isKeyPressed(Input::KEY::LEFT)) {
        move.x = -moveSpeed;
    }
    else if(input.isKeyPressed(Input::KEY::RIGHT)) {
        move.x = moveSpeed;
    } 
    
    if(input.isKeyPressed(Input::KEY::UP)) {
        move.y = -moveSpeed;
    }
    else if(input.isKeyPressed(Input::KEY::DOWN)) {
        move.y = moveSpeed;
    }
    
    float xFrameMove = move.x * deltaTime;
    float yFrameMove = move.y * deltaTime;
    
    cubeSprite.setPosition(spritePos.x + xFrameMove, spritePos.y + yFrameMove);
}

auto SceneGame::draw(Window& window) -> void {
    window.draw(cubeSprite);
}