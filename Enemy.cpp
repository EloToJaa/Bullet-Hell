#include "Header.h"

void Enemy::shoot() {
	double interval;

	if (number_of_shoots % 4 == 0) interval = 3;
	else interval = 0.5;

	while (intf->fpsTimer > interval) {
		deb printf("SHOOTING: %d\n", intf->bullets.size());

		number_of_shoots++;

		intf->fpsTimer -= interval;

		add_bullets();
	}

	int start = intf->bullets.start % Q_SIZE;
	int end = intf->bullets.end % Q_SIZE;

	for (int i = start; i <= end; i++) {
		series(i);
	}
}

void Enemy::series(int k) {
	int direction = intf->bullets.Q[k].direction;

	Vector velocity = { -2, -2 };

	switch (direction) {
	case 0:
		velocity.x = -1;
		break;
	case 1:
		velocity.x = 1;
		break;
	case 2:
		velocity.y = -1;
		break;
	case 3:
		velocity.y = 1;
		break;
	default:
		return;
	}

	intf->bullets.Q[k].update_velocity(velocity);
	intf->bullets.Q[k].move();

	velocity = { -2, -2 };

	switch (direction) {
	case 0:
	case 1:
		velocity.x = 0;
		break;
	case 2:
	case 3:
		velocity.y = 0;
		break;
	}
	intf->bullets.Q[k].update_velocity(velocity);
}

void Enemy::add_bullets() {
	Bullet b;
	b.position = intf->enemy.position;

	b.collider.init(b.position.x, b.position.y, 67, 25);

	// shoot left
	b.set_direction(0);
	intf->bullets.push(b);

	// shoot right
	b.set_direction(1);
	intf->bullets.push(b);

	b.collider.init(b.position.x, b.position.y, 25, 67);

	// shoot up
	b.set_direction(2);
	intf->bullets.push(b);

	// shoot down
	b.set_direction(3);
	intf->bullets.push(b);

	// pop unused bullets
	if (intf->bullets.size() > 80) {
		while (intf->bullets.size() > 16) {
			intf->bullets.pop();
		}
	}
}