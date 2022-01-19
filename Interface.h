#pragma once

#include "Header.h"

struct Interface {
public:
	int t1, t2, quit, frames, rc, fps;
	const int offset = 100;
	double delta, worldTime, fpsTimer, collisionTimer;
	SDL_Event event;
	SDL_Surface* screen, * charset;
	SDL_Texture* scrtex;
	SDL_Window* window;
	SDL_Renderer* renderer;

	Settings settings;
	Colors colors;
	Utils utils;
	Draw draw;
	Player player;
	Enemy enemy;
	Background bg;
	Game game;
	Queue bullets;

	SDL_Surface* bmp[NUMBER_OF_IMAGES];

	void start();

	void event_loop();

	void event_handler();

	void key_down();

	void key_up();

	void init();

	void restart();
};