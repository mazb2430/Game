#include "Enemy.h"
#include "SDL_image.h"
#include "System.h"

Enemy* Enemy::getInstance(const SDL_Rect& r, int s, std::string name, std::string path, double a) {
	return new Enemy(r, s, name, path, a);
}

void Enemy::draw() {
	SDL_RenderCopyEx(sys.getRen(), enemyIcon, nullptr, &getRect(), getAngle(), nullptr, SDL_FLIP_NONE);
}

Enemy::Enemy(const SDL_Rect& r, int s, std::string name, std::string path, double a) : MovingSprite(r, s, a), name(name)
{
	enemyIcon = IMG_LoadTexture(sys.getRen(), path.c_str());
}


Enemy::~Enemy()
{
	SDL_DestroyTexture(enemyIcon);
}
