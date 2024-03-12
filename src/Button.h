#ifndef BUTTONS_H
#define BUTTONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_timer.h>
#include <string>

using namespace std;

enum Buttons { PRESSED , NOTPRESSED , INACTIVE };

class Button {

public:

	//Constructor and destructor
	Button();
	~Button();

	//Methods
	void render(SDL_Renderer* renderer);
	void setText(string text, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
	void setButtonPosition(int x, int y, int w, int h);

	//Methods for states
	void setPressedStateTexture(SDL_Texture* texture);
	void setNotPressedStateTexture(SDL_Texture* texture);
	void setInactiveStateTexture(SDL_Texture* texture);

	//Method for state changes
	void setActive(bool active);
	bool isActive();
	bool isClicked(int mouseX, int mouseY);

	//Method for pressing animation
	void setPressed();
	void delayPress();

private:

	//Attributes
	SDL_Rect butt;
	Buttons buttState;

	//Button States
	SDL_Texture* pressedState;
	SDL_Texture* notPressedState;
	SDL_Texture* inactiveState;

	//Text
	SDL_Texture* textTexture;

	//Pressing timer and state
	Uint32 pressTimer;
	bool pressed;

};

#endif