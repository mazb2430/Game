#include "StuckSprite.h"
#include "System.h"

	StuckSprite::StuckSprite(const SDL_Rect& r, std::string t) :Sprite(r), text(t)
	{
		SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 250,250,250 });
		textureForText = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		SDL_FreeSurface(surf);
	}

	void StuckSprite::setText(std::string newText) {
		text = newText;
		SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 250,250,250 });
		SDL_DestroyTexture(textureForText);
		textureForText = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		SDL_FreeSurface(surf);
	}

	StuckSprite::~StuckSprite()
	{
		SDL_DestroyTexture(textureForText);

	}
