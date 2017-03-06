#include "GameEngine.h"
#include "Label.h"
#include "System.h"
#include "SDL.h"
#include "Character.h"
#include <string>
#include <iostream>
#include "Enemy.h"
#include "FuncButton.h"
#include "Food.h"
using namespace std;

GameEngine engine;
int i = 0;

class MyCharacter : public Character {
public:
	MyCharacter(const SDL_Rect& r, int s, std::string path, double a) :Character(r, s, path, a) {}

	void perform(Sprite* s) {
		if (Enemy* e = dynamic_cast<Enemy*>(s))
			engine.setGameState(3);
		else if (Food* f = dynamic_cast<Food*>(s)) {
 			f->setVisible(true);
			x++;
			if (i == x)
				engine.setGameState(4);
		}
	}

	void handleInput(const SDL_Event& event) {
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			setStepY(-getSpeed());
			setAngle(270);
			break;
		case SDLK_DOWN:
			setStepY(getSpeed());
			setAngle(90);
			break;
		case SDLK_LEFT:
			setStepX(-getSpeed());
			setAngle(180);
			break;
		case SDLK_RIGHT:
			setStepX(getSpeed());
			setAngle(0);
			break;
		}
	}

private:
	int x = 0;

};

class MyEnemy : public Enemy {
public:
	MyEnemy(const SDL_Rect& r, int s, std::string name, std::string path, double a) :Enemy(r, s, name, path, a) {}
	void perform(string name) override {
		if (name == "Turkos") {
			setX(this->getRect().x + getSpeed());
			if (this->getRect().x > (550 - this->getRect().w))
				setY(this->getRect().y + this->getRect().h);
		}
		else if (name == "Pink") {
			setX(this->getRect().x - getSpeed());
			if (this->getRect().x < 0)
				setY(this->getRect().y - this->getRect().h);
		}
		else if (name == "Red") {
			setY(this->getRect().y + getSpeed());
			if (this->getRect().y > (550 - this->getRect().h))
				setX(this->getRect().x - this->getRect().w);
		}
		else if (name == "Yellow") {
			setY(this->getRect().y - getSpeed());
			if (this->getRect().y < 0)
				setX(this->getRect().x + this->getRect().w);
		}
	}
};

void quit(string str) {
	engine.setGameLoopFalse();
}

void play(string str) {
	engine.setGameState(0);
}

void goBack(string str) {
	engine.setGameState(1);
}

void highscore(string str) {
	engine.setGameState(2);
}

int main(int argc, char* argv[]) {

	Sprite* mainMenuLabel = Label::getInstance({ 175,100,200,100 }, "Pacman");
	engine.add(1, mainMenuLabel);
	Sprite* gameOverLabel = Label::getInstance({ 175,185,200,100 }, "Game Over");
	engine.add(3, gameOverLabel);
	Sprite* quitButton = FuncButton::getInstance({ 225, 285, 100, 50 }, "C:/Users/Malek/Desktop/knapp.png", "C:/Users/Malek/Desktop/nerknapp.png", "Quit", quit);
	engine.add(3, quitButton);
	Sprite* completeLabel = Label::getInstance({ 175,185,200,100 }, "You Won!!");
	engine.add(4, completeLabel);
	Sprite* quitButton2 = FuncButton::getInstance({ 225, 285, 100, 50 }, "C:/Users/Malek/Desktop/knapp.png", "C:/Users/Malek/Desktop/nerknapp.png", "Quit", quit);
	engine.add(4, quitButton2);
	Sprite* mainButton = FuncButton::getInstance({ 225, 200, 100, 50 }, "C:/Users/Malek/Desktop/knapp.png", "C:/Users/Malek/Desktop/nerknapp.png", "Play", play);
	engine.add(1, mainButton);

	Sprite* mainButton2 = FuncButton::getInstance({ 225, 275, 100,50 }, "C:/Users/Malek/Desktop/knapp.png", "C:/Users/Malek/Desktop/nerknapp.png", "Highscore", highscore);
	engine.add(1, mainButton2);
	Sprite* gameButton2 = FuncButton::getInstance({ 430, 485, 100, 50 }, "C:/Users/Malek/Desktop/knapp.png", "C:/Users/Malek/Desktop/nerknapp.png", "Return", goBack);
	engine.add(2, gameButton2);
	for (int x = 10; x < 550; x += 25) {
		for (int y = 10; y < 550; y += 25) {
			Sprite* foodRect = Food::getInstanse({ x,y,5,5 }, "C:/Users/Malek/Desktop/vit.png");
			engine.add(0, foodRect);
			i++;
		}
	}
	Sprite* gameCharacter = new MyCharacter({ 275,275,25,23 }, 4, "C:/Users/Malek/Desktop/pacman.png", 270.0);
	engine.add(0, gameCharacter);
	Sprite* gameEnemy = new MyEnemy({ 0, 0, 25, 25 }, 3, "Turkos", "C:/Users/Malek/Desktop/pacman-turkos.png", 0.0);
	engine.add(0, gameEnemy);
	Sprite* gameEnemy2 = new MyEnemy({ 550, 550, 25, 25 }, 3, "Pink", "C:/Users/Malek/Desktop/pacman-pink.png", 0.0);
	engine.add(0, gameEnemy2);
	Sprite* gameEnemy3 = new MyEnemy({ 525, 0, 25, 25 }, 3, "Red", "C:/Users/Malek/Desktop/pacman-red.png", 0.0);
	engine.add(0, gameEnemy3);
	Sprite* gameEnemy4 = new MyEnemy({ 0, 525, 25, 25 }, 3, "Yellow", "C:/Users/Malek/Desktop/pacman-yellow.png", 0.0);
	engine.add(0, gameEnemy4);
	engine.run();

	return 0;
}