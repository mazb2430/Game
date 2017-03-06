#ifndef LABEL_H
#define LABEL_H
#include "StuckSprite.h"


class Label :
	public StuckSprite
{
public:
	static Label* getInstance(const SDL_Rect& rect, std::string text);
	void draw();
protected:
	Label(const SDL_Rect& rect, std::string text);
};

#endif

