#ifndef ENEMY_H
#define ENEMY_H
#include "MovingSprite.h"

class Enemy :
	public MovingSprite
{
public:
	static Enemy* getInstance(const SDL_Rect& r, int s, std::string name, std::string path, double a);
	void draw();
	std::string getName() { return name; }
	virtual void perform(std::string name){}
	~Enemy();
protected:
	Enemy(const SDL_Rect& r, int s, std::string name, std::string path, double a);
private:
	SDL_Texture* enemyIcon;
	std::string name;
};

#endif

