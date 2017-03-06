#ifndef STUCKSPRITE_H
#define STUCKSPRITE_H
#include "Sprite.h"
#include "SDL.h"
#include <string>


class StuckSprite :
	public Sprite
{
public:
	StuckSprite(const SDL_Rect& r, std::string t);
	std::string getText() const { return text; }
	void setText(std::string newText);
	~StuckSprite();
protected:
	SDL_Texture* getTexture() const { return textureForText; }
private:
	std::string text;
	SDL_Texture* textureForText;
};

#endif

