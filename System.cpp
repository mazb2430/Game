#include "System.h"
#include <iostream>

void System::errorMessage(std::string message) {
	std::cerr << message << SDL_GetError << std::endl;
	std::cout << "Press any key to quit" << std::endl;
	int pressAnyKey;
	std::cin >> pressAnyKey;
	SDL_Quit();
}

System::System()
{
	code = SDL_Init(SDL_INIT_EVERYTHING);
	if (code == -1)
		errorMessage("Could not initialize SDL: ");

	win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		550, 550, SDL_WINDOW_SHOWN);
	if (win == nullptr)
		errorMessage("Could not open window: ");

	ren = SDL_CreateRenderer(win, -1, 0);
	if (ren == nullptr)
		errorMessage("Could ot open renderer: ");

	TTF_Init();
	font = TTF_OpenFont("C:/Users/Malek/Desktop/crackman.ttf", 24);
	if (font == nullptr)
		errorMessage("Could not open font. ");

	Mix_OpenAudio(22050, AUDIO_S16SYS, 1, 4096);
	music = Mix_LoadWAV("C:/Users/Malek/Desktop/bgMusic.wav");
	if (music == nullptr)
		errorMessage("No music.");
}


System::~System()
{
	Mix_CloseAudio();
	Mix_Quit();
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

System sys;