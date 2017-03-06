#ifndef BUTTON_H
#define BUTTON_H
#include "StuckSprite.h"

class Button :
	public StuckSprite
{
public:
	static Button* getInstance(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string t);
	void mouseUp(const SDL_Event& eve);
	void mouseDown(const SDL_Event& eve);
	void draw();
	virtual void perform(std::string) {}
	~Button();
protected:
	Button(const SDL_Rect& r, std::string pathUp, std::string pathDown, std::string t);
private:
	SDL_Texture* upIcon, *downIcon;
	bool isDown = false;
};

#endif