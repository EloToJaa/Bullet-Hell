#include "Header.h"

void Draw::init(SDL_Surface* screen, Interface* intf) {
	this->intf = intf;
	this->screen = screen;
}

void Draw::string(int x, int y, const char* text) {
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while (*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		x += 8;
		text++;
	}
}

void Draw::surface(SDL_Surface* sprite, int x, int y) {
	SDL_Rect dest;
	dest.x = x - sprite->w / 2;
	dest.y = y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void Draw::pixel(int x, int y, Uint32 color) {
	int bpp = screen->format->BytesPerPixel;
	Uint8* p = (Uint8*)screen->pixels + y * screen->pitch + x * bpp;
	*(Uint32*)p = color;
}

void Draw::line(int x, int y, int l, int dx, int dy, Uint32 color) {
	for (int i = 0; i < l; i++) {
		pixel(x, y, color);
		x += dx;
		y += dy;
	}
}

void Draw::rectangle(int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor = -1) {
	line(x, y, k, 0, 1, outlineColor);
	line(x + l - 1, y, k, 0, 1, outlineColor);
	line(x, y, l, 1, 0, outlineColor);
	line(x, y + k - 1, l, 1, 0, outlineColor);

	if (fillColor != -1) {
		for (int i = y + 1; i < y + k - 1; i++) {
			line(x + 1, i, l - 2, 1, 0, fillColor);
		}
	}
}

void Draw::image(const char key[MAX_STRING], int x, int y) {
	int id = intf->utils.get_key_id(key);
	surface(intf->bmp[id], x, y);
}

void Draw::message(char text[MAX_STRING]) {
	msg_line++;
	string(screen->w - strlen(text) * 8 - 10, msg_line * 10, text);
}

void Draw::start(SDL_Surface* charset) {
	msg_line = 0;
	this->charset = charset;
	char text[MAX_STRING];

	Background bg = intf->bg;
	Player player = intf->player;
	Enemy enemy = intf->enemy;

	// Background
	image(bg.name, bg.position.x, bg.position.y);

	// Player
	image(player.name, player.position.x, player.position.y);
	//deb rectangle(player.collider.rect.x, player.collider.rect.y, player.collider.rect.w, player.collider.rect.h, intf->colors.red);

	// Enemy
	image(enemy.name, enemy.position.x, enemy.position.y);
	//deb rectangle(enemy.collider.rect.x, enemy.collider.rect.y, enemy.collider.rect.w, enemy.collider.rect.h, intf->colors.green);

	// Bullets
	int start = intf->bullets.start % Q_SIZE;
	int end = intf->bullets.end % Q_SIZE;
	for (int i = start; i <= end; i++) {
		Bullet b = intf->bullets.Q[i];
		image(b.name, b.position.x, b.position.y);
		//deb rectangle(b.collider.rect.x, b.collider.rect.y, b.collider.rect.w, b.collider.rect.h, intf->colors.white);
	}

	sprintf(text, "Time: %.1lf s", intf->worldTime);
	message(text);

	sprintf(text, "Player Health: %d", intf->player.health);
	message(text);

	sprintf(text, "Enemy Health: %d", intf->enemy.health);
	message(text);

	deb{
		sprintf(text, "Player:: X:%d Y:%d", player.position.x, player.position.y);
		message(text);

		sprintf(text, "Enemy:: X:%d Y:%d", enemy.position.x, enemy.position.y);
		message(text);

		sprintf(text, "BG:: X:%d Y:%d", bg.position.x, bg.position.y);
		message(text);
	}
}