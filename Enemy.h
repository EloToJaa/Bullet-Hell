#pragma once
#include "Header.h"

struct Enemy : public Entity {
	Interface* intf;

	int number_of_shoots = 0;

	void shoot();

	void series(int k);

	void add_bullets();
};