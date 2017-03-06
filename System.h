#ifndef SYSTEM_H
#define SYSTEM_H
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>

class System
{
public:
	System();
	SDL_Renderer* getRen() const { return ren; }
	TTF_Font* getFont() const { return font; }
	Mix_Chunk* getMusic() const { return music; }
	~System();

private:
	SDL_Window* win;
	SDL_Renderer* ren;
	TTF_Font* font;
	Mix_Chunk* music;
	int code;
	void errorMessage(std::string message);
};

extern System sys;

#endif

