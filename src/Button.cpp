#include "Button.h"

//Constructor
Button::Button() {

	buttState = NOTPRESSED;
	pressedState = nullptr;
	notPressedState = nullptr;
	inactiveState = nullptr;
	butt = { 0, 0 , 100, 50 };

}

//Destructor
Button::~Button() {
	
	SDL_DestroyTexture(pressedState);
	SDL_DestroyTexture(notPressedState);
	SDL_DestroyTexture(inactiveState);

}

//Method to set the text of the button
void Button::setText(string text, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer) {

	
	if (textTexture != nullptr) {
		SDL_DestroyTexture(textTexture);
		textTexture = nullptr; 
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (textSurface != nullptr) { 
		textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_FreeSurface(textSurface);
	}
}

//Method to render the button based on the state
void Button::render(SDL_Renderer* renderer) {
	SDL_Texture* currentTexture = nullptr;

	if (pressed && SDL_GetTicks() - pressTimer <= 200) {
		currentTexture = pressedState;
	}
	else {
		switch (buttState) {
		case PRESSED:
			currentTexture = pressedState;
			break;
		case NOTPRESSED:
			currentTexture = notPressedState;
			break;
		case INACTIVE:
			currentTexture = inactiveState;
			break;
		}
	}

	if (currentTexture != nullptr) {
		SDL_RenderCopy(renderer, currentTexture, NULL, &butt);
	}

	if (textTexture != nullptr) {
		int textWidth, textHeight;
		SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect textRect = { butt.x + (butt.w - textWidth) / 2, butt.y + (butt.h - textHeight) / 2, textWidth, textHeight };

		SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
	}
}

//Method to handle the button position
void Button::setButtonPosition(int x, int y, int w, int h) {
	butt.x = x;
	butt.y = y;
	butt.w = w;
	butt.h = h;
}

//Methods for state textures
void Button::setPressedStateTexture(SDL_Texture* texture) {
	pressedState = texture;
}

void Button::setNotPressedStateTexture(SDL_Texture* texture) {
	notPressedState = texture;
}

void Button::setInactiveStateTexture(SDL_Texture* texture) {
	inactiveState = texture;
}

//Methods for state changes
void Button::setActive(bool active) {
	if (active) {
		buttState = NOTPRESSED;
	}
	else {
		buttState = INACTIVE;
	}
}

bool Button::isActive() {
	return buttState != INACTIVE;
}

bool Button::isClicked(int mouseX, int mouseY) {
	SDL_Point mousePoint = { mouseX, mouseY };
	return SDL_PointInRect(&mousePoint, &butt);
}

//Method to handle button press
void Button::setPressed() {

	pressed = true;
	pressTimer = SDL_GetTicks();
	buttState = PRESSED;

}

//Method to handle the delay
void Button::delayPress() {
	if (pressed && SDL_GetTicks() - pressTimer > 200) {
		pressed = false;
		if (isActive()) {
			buttState = NOTPRESSED;
		}
		else {
			buttState = INACTIVE;
		}
	}
}