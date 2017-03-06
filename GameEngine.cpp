#include "GameEngine.h"
#include "System.h"
#include "MovingSprite.h"
#include "SDL.h"
#include "Character.h"
#include "Enemy.h"
#include <iostream>
#define FPS 60

void GameEngine::turnOnOrOffMusic() {
	if (onOff) {
		Mix_VolumeChunk(sys.getMusic(), 0);
		onOff = false;
	}
	else if (getGameState() == GAMEOVER) {
		Mix_VolumeChunk(sys.getMusic(), 0);
		onOff = false;
	}
	else {
		Mix_VolumeChunk(sys.getMusic(), 100);
		onOff = true;
	}
}

void GameEngine::handleNoneCharacterInput() {
	switch (event.key.keysym.sym) {
	case SDLK_F10:
		turnOnOrOffMusic();
		break;
	}
}

void GameEngine::setGameLoopFalse() {
	goOn = false;
}

void GameEngine::add(int event, Sprite* sprite) {
	eventMap[event].push_back(sprite);
}

void GameEngine::setGameState(int newState) {
	gameState = newState;
}

void GameEngine::run() {
	const int TIDPERVARV = 1000 / FPS;
	Mix_PlayChannel(1, sys.getMusic(), -1);
	while (goOn) {
		Uint32 nextTick = SDL_GetTicks() + TIDPERVARV;
		input();
		for (auto s : eventMap.at(getGameState())) {
			if (Enemy* e = dynamic_cast<Enemy*>(s))
				e->perform(e->getName());
			s->tick();
			if (Character* c = dynamic_cast<Character*>(s)) {
				c->checkForCollision(eventMap.at(getGameState()));

			}
		}

		SDL_RenderClear(sys.getRen());

		switch (gameState) {
		case MENU:
			for (Sprite* s : eventMap.at(1))
				s->draw();
			break;
		case PLAY:
			for (Sprite* s : eventMap.at(0)) {
				s->draw();
			}
			break;
		case HIGHSCORE:
			for (Sprite* s : eventMap.at(2))
				s->draw();
			break;
		case GAMEOVER:
			turnOnOrOffMusic();
			for (Sprite* s : eventMap.at(3))
				s->draw();
			break;
		case WON:
			for (Sprite* s : eventMap.at(4))
				s->draw();
			break;
		}
		SDL_RenderPresent(sys.getRen());


		int delay = nextTick - SDL_GetTicks();
		if (delay > 0)
			SDL_Delay(delay);

	}

}

void GameEngine::input() {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: setGameLoopFalse(); break;
		case SDL_MOUSEBUTTONDOWN:
			for (Sprite* s : eventMap.at(getGameState()))
				s->mouseDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			for (Sprite* s : eventMap.at(getGameState()))
				s->mouseUp(event);
			break;
		case SDL_KEYDOWN:
			for (Sprite* s : eventMap.at(getGameState())) {
				Character* c = dynamic_cast<Character*>(s);
				if (c != nullptr) {
					c->keyDown(event);
				}
			}
			handleNoneCharacterInput();
			break;
		case SDL_KEYUP:
			for (Sprite* s : eventMap.at(getGameState())) {
				Character* c = dynamic_cast<Character*>(s);
				if (c != nullptr) {
					c->keyUp(event);
				}
			}
			break;
		}
	}
}

GameEngine::~GameEngine()
{
	for (auto iterator = eventMap.begin(); iterator != eventMap.end(); iterator++)
		for (auto s : iterator->second) {
			delete s;
		}
}