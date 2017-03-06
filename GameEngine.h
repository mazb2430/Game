#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include "Sprite.h"
#include "SDL.h"
#include <map>
#include <list>

class GameEngine
{
public:
	void add(int event, Sprite* sprite);
	void run();
	void setGameState(int newState);
	void handleNoneCharacterInput();
	void setGameLoopFalse();
	void turnOnOrOffMusic();
	int getGameState() const { return gameState; }
	void input();
	~GameEngine();

private:
	std::map<int, std::list<Sprite*> > eventMap;
	SDL_Event event;
	bool goOn = true;
	enum gameState {PLAY, MENU, HIGHSCORE, GAMEOVER, WON};
	int gameState = MENU;
	bool onOff = true;
};

#endif
