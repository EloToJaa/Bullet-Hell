#include "Header.h"

bool Player::in_center() {
	return (start_min.x == min.x && start_max.x == max.x && start_min.y == min.y && start_max.y == max.y);
}

void Player::set_direction(bool direction) {
	this->direction = direction;
	if (direction) {
		set_name("right");
	}
	else {
		set_name("left");
	}
}