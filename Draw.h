#pragma once

#include "Header.h"

struct Draw {
public:
	SDL_Surface* screen, *charset;

	Interface* intf;

	int msg_line;

	// create object
	void init(SDL_Surface* screen, Interface* interface);

	// start drawing whats necessary
	void start(SDL_Surface* charset);

	// draw a text txt on surface screen, starting from the point (x, y)
	// charset is a 128x128 bitmap containing character images
	void string(int x, int y, const char* text);

	// draw a surface sprite on a surface screen in point (x, y)
	// (x, y) is the center of sprite on screen
	void surface(SDL_Surface* sprite, int x, int y);

	// draw a single pixel
	void pixel(int x, int y, Uint32 color);

	// draw a vertical (when dx = 0, dy = 1) or horizontal (when dx = 1, dy = 0) line
	void line(int x, int y, int l, int dx, int dy, Uint32 color);

	// draw a rectangle of size l by k
	void rectangle(int x, int y, int l, int k, Uint32 outlineColor, Uint32 fillColor);

	// draw an image
	void image(const char key[MAX_STRING], int x, int y);

	void message(char text[MAX_STRING]);
};