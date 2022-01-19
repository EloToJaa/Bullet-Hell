#pragma once
#include "Header.h"

struct Bullet: public Entity {
	int direction = 0;

	// 0 - left, 1 - right, 2 - up, 3 - down
	void set_direction(int direction);
};