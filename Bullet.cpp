#include "Header.h"

void Bullet::set_direction(int direction) {
	char* name;
	this->direction = direction;

	switch (direction) {
	case 0:
		name = "bullet_left";
		break;
	case 1:
		name = "bullet_right";
		break;
	case 2:
		name = "bullet_up";
		break;
	case 3:
		name = "bullet_down";
		break;
	default:
		return;
	}

	set_name(name);
}