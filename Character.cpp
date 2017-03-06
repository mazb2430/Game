#include "Character.h"
#include "SDL_image.h"
#include "System.h"
#include "GameEngine.h"
#include <iostream>
#include "SDL.h"

void Character::checkForCollision(std::list <Sprite*> list) {
	GameEngine engine;
	for (auto s : list) {
		if (this != s && !s->getVisible() && collision(&s->getRect())) {
			std::cout << "Krock!!!" << std::endl;
			perform(s);
		}

	}
}

bool Character::collision(const SDL_Rect* or ) {
	if (getRect().y >= or ->y + or ->h)
		return 0;
	if (getRect().x >= or ->x + or ->w)
		return 0;
	if (getRect().y + getRect().h <= or ->y)
		return 0;
	if (getRect().x + getRect().w <= or ->x)
		return 0;
	return 1;
}

void Character::keyDown(const SDL_Event& event) {
	handleInput(event);
}

void Character::keyUp(const SDL_Event& event) {
	setStepX(0);
	setStepY(0);
}

Character* Character::getInstance(const SDL_Rect& r, int s, std::string path, double a) {
	return new Character(r, s, path, a);
}

Character::Character(const SDL_Rect& r, int s, std::string path, double a) : MovingSprite(r, s, a)
{
	icon = IMG_LoadTexture(sys.getRen(), path.c_str());
}

void Character::draw() {
	SDL_RenderCopyEx(sys.getRen(), icon, nullptr, &getRect(), getAngle(), nullptr, SDL_FLIP_NONE);
}

Character::~Character()
{
	SDL_DestroyTexture(icon);
}
