#include "C_Animation.h"
#include "Animation.h"
#include <utility>

C_Animation::C_Animation(Object* owner) : Component(owner) {}

auto C_Animation::awake() -> void {
    sprite = getOwner()->getComponent<C_Sprite>();
}

auto C_Animation::update(float deltaTime) -> void {
    if (currentAnimation.first != AnimationState::None) {
        auto newFrame = currentAnimation.second->updateFrame(deltaTime);

        if (newFrame) {
            const auto& data = currentAnimation.second->getCurrentFrame();
            sprite->load(data->id);
            sprite->setTextureRect(data->x, data->y, data->width, data->height);
        }
    }
}

auto C_Animation::addAnimation(AnimationState state, std::shared_ptr<Animation> animation) -> void {
    auto inserted = animations.insert(std::make_pair(state, animation));

    if (currentAnimation.first == AnimationState::None) {
        setAnimationState(state);
    }
}

auto C_Animation::setAnimationState(AnimationState state) -> void {
	// We only set an animation of it is not already 
	// our current animation.
    if (currentAnimation.first == state) {
        return;
    }
    
    auto animation = animations.find(state);
    if (animation != animations.end()) {
        currentAnimation.first = animation->first;
        currentAnimation.second = animation->second;
        
        currentAnimation.second->reset();
    }
}

auto C_Animation::getAnimationState() const -> const AnimationState& {
	// Returns out current animation state. We can use this 
	// to compare the objects current state to a desired state.
    return currentAnimation.first; 
}

auto C_Animation::setAnimationDirection(FacingDirection facingDirection) -> void {
    if (currentAnimation.first != AnimationState::None) {
        currentAnimation.second->setDirection(facingDirection);
    }
}