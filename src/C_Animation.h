#pragma once

#include "Animation.h"
#include "Component.h"
#include "Object.h"
#include "C_Sprite.h"
#include <map>
#include <memory.h>

enum class AnimationState {
    None,
    Idle,
    Walk
};

class C_Animation : public Component {
public:
    C_Animation(Object* owner);

    auto awake() -> void override;

    auto update(float deltaTime) -> void override;
    
	// Add animation to object. We need its state as well 
	// so that we can switch to it.
    auto addAnimation(AnimationState state, std::shared_ptr<Animation> animation) -> void;
	
	// Set current animation states.
    auto setAnimationState(AnimationState state) -> void;
	
	// Returns current animation state.
    [[nodiscard]] auto getAnimationState() const -> const AnimationState&;

private:
    std::shared_ptr<C_Sprite> sprite;
    std::map<AnimationState, std::shared_ptr<Animation>> animations;
	
	// We store a reference to the current animation so we 
	// can quickly update and draw it.
    std::pair<AnimationState, std::shared_ptr<Animation>> currentAnimation{AnimationState::None, nullptr};
};