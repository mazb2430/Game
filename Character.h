#ifndef CHARACTER_H
#define CHARACTER_H
#include "MovingSprite.h"
#include <string>
#include <list>

class Character :
	public MovingSprite
{
public:
	static Character* getInstance(const SDL_Rect& r, int s, std::string path, double a);
	void draw();
	void keyUp(const SDL_Event& event);
	void keyDown(const SDL_Event& event);
	virtual void handleInput(const SDL_Event& event){}
	bool collision(const SDL_Rect* otherRect);
	void checkForCollision(std::list <Sprite*> list);
	virtual void perform(Sprite* s){}
	~Character();
protected:
	Character(const SDL_Rect& r, int s, std::string path, double a);
private:
	SDL_Texture* icon;
};

#endif