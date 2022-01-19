#pragma once
#include "Header.h"

struct Player : public Entity {
	// false - left, true - right
	bool direction;

	bool in_center();

	// false - left, true - right
	void set_direction(bool direction);
};