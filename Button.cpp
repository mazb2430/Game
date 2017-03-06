#include "Button.h"
#include <SDL_image.h>
#include "System.h"

Button* Button::getInstance(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string t) {
	return new Button(r, pathUp, pathDown, t);
}


Button::Button(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string t) :
	StuckSprite(r, t)
{
	upIcon = IMG_LoadTexture(sys.getRen(), pathUp.c_str());
	downIcon = IMG_LoadTexture(sys.getRen(), pathDown.c_str());
}

void Button::mouseDown(const SDL_Event& eve) {
	SDL_Point p = { eve.button.x, eve.button.y };
	if (SDL_PointInRect(&p, &getRect()))
		isDown = true;
}

void Button::draw() {
	if(isDown)
		SDL_RenderCopy(sys.getRen(), downIcon, NULL, &getRect());
	else
		SDL_RenderCopy(sys.getRen(), upIcon, NULL, &getRect());
	SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
}

void Button::mouseUp(const SDL_Event& eve) {
	SDL_Point p = { eve.button.x, eve.button.y };
	if (isDown && SDL_PointInRect(&p, &getRect())) {
		perform(getText());
	}
	isDown = false;
}

Button::~Button()
{
	SDL_DestroyTexture(upIcon);
	SDL_DestroyTexture(downIcon);
}

