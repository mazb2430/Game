#include "Label.h"
#include "System.h"

Label::Label(const SDL_Rect& r, std::string t) :StuckSprite(r, t)
{
}

Label* Label::getInstance(const SDL_Rect& rect, std::string text) {
	return new Label(rect, text);
}

void Label::draw() {
	SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
}
