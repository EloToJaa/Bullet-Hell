#pragma once

#include "Header.h"

struct Entity {
	Vector position, velocity, min, max, start_min, start_max;
	Collider collider;
	int health, damage, speed;
	bool border;
	char name[MAX_STRING];

	Entity();

	bool move();

	void set_border(int start_x, int start_y, int end_x, int end_y);

	void update_velocity(Vector velocity);

	void set_name(char name[MAX_STRING]);
};