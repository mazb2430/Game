#include "MovingSprite.h"
#include "System.h"
#include <iostream>

void MovingSprite::tick() {
	setX(getRect().x + stepX);
	setY(getRect().y + stepY);
}

void MovingSprite::setStepY(int y) {
	stepY = y;
}
void MovingSprite::setStepX(int x) {
	stepX = x;
}

MovingSprite::MovingSprite(const SDL_Rect& r, int s, double a):Sprite(r), speed(s), angle(a)
{
}

void MovingSprite::setAngle(double newAngel) {
	angle = newAngel;
}

MovingSprite::~MovingSprite()
{
}
