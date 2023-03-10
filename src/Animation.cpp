#include "Animation.h"

Animation::Animation(FacingDirection facingDirection) : facingDirection(facingDirection) {}

auto Animation::addFrame(int textureId, int x, int y, int width, int height, float frameTime) -> void {
    frames.push_back(FrameData{textureId, x, y, width, height, frameTime});
}

auto Animation::getCurrentFrame() const -> const FrameData* {
    if (!frames.empty()) {
        return &frames.at(currentFrameIndex);
    }

    return nullptr;
}

auto Animation::updateFrame(float deltaTime) -> bool {
    if (!frames.empty()) {
        currentFrameTime += deltaTime;

        if (currentFrameTime >= frames.at(currentFrameIndex).displayTimeSeconds) {
            currentFrameTime = 0.F;
            incrementFrame();
            return true;
        }
    }

    return false;
}

auto Animation::reset() -> void {
    currentFrameIndex = 0;
    currentFrameTime = 0.F;
}

auto Animation::incrementFrame() -> void {
    currentFrameIndex = (currentFrameIndex + 1) % static_cast<int>(frames.size());
}

auto Animation::setDirection(FacingDirection facingDirection) -> void {
    if (this->facingDirection != facingDirection) {
        this->facingDirection = facingDirection;

        for (auto& frame : frames) {
            frame.x += frame.width;
            frame.width *= -1;
        }
    }
}

auto Animation::getDirection() const -> FacingDirection {
    return facingDirection;
}