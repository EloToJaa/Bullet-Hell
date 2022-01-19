#include "Header.h"

Entity::Entity() {
	velocity.x = 0;
	velocity.y = 0;
	position.x = 0;
	position.y = 0;
	speed = 5;
	health = 100;
	damage = 5;

	border = false;
	min.x = -1;
	min.y = -1;
	max.x = -1;
	max.x = -1;

	start_max = max;
	start_min = min;

	set_name("entity");
}

void Entity::set_border(int start_x, int start_y, int end_x, int end_y) {
	min.x = start_x;
	min.y = start_y;
	max.x = end_x;
	max.y = end_y;
	if (!border) {
		start_min = min;
		start_max = max;
	}
	border = true;
}

bool Entity::move() {
	if (border) {
		bool moved = false;
		if (velocity.x != 0 && position.x + velocity.x * speed >= min.x && position.x + velocity.x * speed <= max.x) {
			position.x += velocity.x * speed;
			moved = true;
		}
		if (velocity.y != 0 && position.y + velocity.y * speed >= min.y && position.y + velocity.y * speed <= max.y) {
			position.y += velocity.y * speed;
			moved = true;
		}

		collider.set_position(position);

		if (moved) return true;
		return false;
	}
	else {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;

		collider.set_position(position);
		return true;
	}
}

void Entity::update_velocity(Vector velocity) {
	if (velocity.x != -2) this->velocity.x = velocity.x;
	if (velocity.y != -2) this->velocity.y = velocity.y;
}

void Entity::set_name(char name[MAX_STRING]) {
	for (int i = 0; i < MAX_STRING; i++) {
		this->name[i] = name[i];
	}
}