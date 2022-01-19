#include "Header.h"

void Game::place() {
	SDL_Surface* screen = intf->screen;
	int offset = intf->offset;

	// Player
	intf->player.position.x = screen->w / 2;
	intf->player.position.y = screen->h / 2;
	intf->player.set_direction(true);
	intf->player.set_border(offset, offset, screen->w - offset, screen->h - offset);

	Vector position = intf->player.position;
	intf->player.collider.init(position.x, position.y, 100, 72);

	// Background
	intf->bg.set_border(0, 0, intf->settings.BG_WIDTH / 2, intf->settings.BG_HEIGHT / 2);
	intf->bg.set_name("bg");

	// Enemy
	intf->enemy.position.x = -300;
	intf->enemy.position.y = -300;
	intf->enemy.set_name("enemy1");

	position = intf->enemy.position;
	intf->enemy.collider.init(position.x, position.y, 90, 98);
}