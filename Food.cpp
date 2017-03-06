#include "Food.h"
#include "SDL_image.h"
#include "System.h"

Food* Food::getInstanse(const SDL_Rect& r, std::string path) {
	return new Food(r, path);
}

Food::Food(const SDL_Rect& r, std::string path) : Sprite(r)
{
	icon = IMG_LoadTexture(sys.getRen(), path.c_str());
}

void Food::draw() {
	if (!getVisible())
		SDL_RenderCopy(sys.getRen(), icon, NULL, &getRect());
}

Food::~Food()
{
	SDL_DestroyTexture(icon);
}
