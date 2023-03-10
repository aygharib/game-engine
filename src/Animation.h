#pragma once

#include <vector>

enum class FacingDirection {
    None,
    Left,
    Right
};

struct FrameData {
    int id; // Texture id (retrieved from our texture allocator).
    int x; // x position of sprite in the texture.
    int y; // y position of sprite in the texture.
    int width; // Width of sprite.
    int height; // Height of sprite.
    float displayTimeSeconds; // How long to display the frame.
};

class Animation {
public:
    Animation(FacingDirection FacingDirection);

    auto addFrame(int textureId, int x, int y, int width, int height, float frameTime) -> void;
    
    [[nodiscard]] auto getCurrentFrame() const -> const FrameData*;
    
    auto updateFrame(float deltaTime) -> bool;
    
    auto reset() -> void;

    auto setDirection(FacingDirection facingDirection) -> void;
    [[nodiscard]] auto getDirection() const -> FacingDirection;
    
private:
    FacingDirection facingDirection;
    
	// Stores all frames for our animation.
    std::vector<FrameData> frames{0};
	
	// Current frame.
    int currentFrameIndex{0};
	
	// We use this to decide when to transition to the next frame.
    float currentFrameTime{0.F};
    
    auto incrementFrame() -> void;
};