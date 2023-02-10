#include "SceneSplashScreen.h"

SceneSplashScreen::SceneSplashScreen(WorkingDirectory& workingDirectory, 
									 SceneStateMachine& sceneStateMachine,
									 Window& window) 
    : sceneStateMachine(sceneStateMachine), workingDirectory(workingDirectory), window(window),
    switchToState(0), currentSeconds(0.F), showForSeconds(3.F) {}

void SceneSplashScreen::onCreate() {
	// We’ll initialise our splash screen image here.
	
    splashTexture.loadFromFile(workingDirectory.get() + "splash.png");
    splashSprite.setTexture(splashTexture);
    
    auto spriteSize = splashSprite.getLocalBounds();
	
	// Set the origin of the sprite to the centre of the image:
    splashSprite.setOrigin(spriteSize.width / 2.F, 
						   spriteSize.height / 2.F);
    
    auto windowCentre = window.getCenter();

	// Positions sprite in centre of screen:
    splashSprite.setPosition(windowCentre.x, windowCentre.y); 
}

void SceneSplashScreen::onActivate() {
	// Resets the currentSeconds count whenever the scene is activated.
	currentSeconds = 0.F;
}

void SceneSplashScreen::onDestroy() {}

void SceneSplashScreen::setSwitchToScene(unsigned int id) {
	// Stores the id of the scene that we will transition to.
    switchToState = id; 
}

void SceneSplashScreen::update(float deltaTime) {
    currentSeconds += deltaTime;
    
    if (currentSeconds >= showForSeconds) {
		// Switches states.
        sceneStateMachine.switchTo(switchToState); 
    }
}

void SceneSplashScreen::draw(Window& window) {
    window.draw(splashSprite);
}