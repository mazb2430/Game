#ifndef FOOD_H
#define FOOD_H
#include "Sprite.h"
#include <string>
class Food :
	public Sprite
{
public:
	static Food* getInstanse(const SDL_Rect& r, std::string path);
	void draw();
	~Food();
protected:
	Food(const SDL_Rect& r, std::string path);
private:
	SDL_Texture* icon;
};

#endif

