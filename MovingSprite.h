#ifndef MOVINGSPRITE_H
#define MOVINGSPRITE_H
#include "Sprite.h"
#include "SDL.h"
#include <string>

class MovingSprite :
	public Sprite
{
public:
	MovingSprite(const SDL_Rect& r, int speed, double a);
	double getAngle() const { return angle; }
	int getStepX() const { return stepX; }
	int getStepY() const { return stepY; }
	void setStepY(int y);
	void setStepX(int x);
	void tick();
	void setAngle(double newAngel);
	int getSpeed() const { return speed; }
	~MovingSprite();
private:
	double angle;
	int speed;
	int stepX;
	int stepY;
};

#endif
