#pragma once

#include "Header.h"

struct Colors {
public:
	SDL_Surface* screen;
	int red, green, blue, black, white;

	void init(SDL_Surface* new_screen);
	int get(int R, int G, int B);
};