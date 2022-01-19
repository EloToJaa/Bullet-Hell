#include "Header.h"

void Colors::init(SDL_Surface* new_screen) {
	screen = new_screen;
	black = SDL_MapRGB(screen->format, 0x00, 0x00, 0x00);
	white = SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF);
	green = SDL_MapRGB(screen->format, 0x00, 0xFF, 0x00);
	red = SDL_MapRGB(screen->format, 0xFF, 0x00, 0x00);
	blue = SDL_MapRGB(screen->format, 0x11, 0x11, 0xCC);
}

int Colors::get(int R, int G, int B) {
	int color = SDL_MapRGB(screen->format, R, G, B);
	return color;
}