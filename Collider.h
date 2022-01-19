#pragma once
#include "Header.h"

struct Collider {
	SDL_Rect rect;
	
	bool collision(Collider col);

	void init(int x, int y, int w, int h);

	void set_position(Vector position);
};