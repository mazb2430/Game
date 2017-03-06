#include "Sprite.h"
#include <iostream>

Sprite::Sprite(const SDL_Rect& r) : rect(r)
{
}

Sprite::~Sprite()
{
	
}

void Sprite::setVisible(bool c) {
	visible = c;
}

void Sprite::setX(int x) {
	if (rect.x < 0) {
		rect.x = 550 - rect.w;
	}
	else if (rect.x > 550 - rect.w) {
		rect.x = 0;
	}
	else {
		rect.x = x;
	}
}

void Sprite::setY(int y) {
	if (rect.y < 0) {
		rect.y = 550 - rect.h;
	}
	else if (rect.y > 550 - rect.h) {
		rect.y = 0;
	}
	else {
		rect.y = y;
	}
}