#include "Header.h"

SDL_Surface* Utils::load_bmp(const char file_name[MAX_STRING]) {
	char new_name[MAX_STRING];
	sprintf(new_name, "./img/%s", file_name);
	SDL_Surface* bmp = SDL_LoadBMP(new_name);
	if (bmp == NULL) {
		printf("SDL_LoadBMP(%s.bmp) error: %s\n", new_name, SDL_GetError());
		destroy_window(1);
	}
	SDL_SetColorKey(bmp, SDL_TRUE, SDL_MapRGB(bmp->format, 0xFF, 0, 0xFF));
	return bmp;
}

int Utils::get_key_id(const char key[MAX_STRING]) {
	for (int i = 0; i < NUMBER_OF_IMAGES; i++) {
		if (strcmp(intf->settings.IMAGES[i][0], key) == 0) {
			return i;
		}
	}
	return -1;
}

void Utils::load_bmps() {
	for (int i = 0; i < NUMBER_OF_IMAGES; i++) {
		intf->bmp[i] = load_bmp(intf->settings.IMAGES[i][1]);
	}
}

void Utils::catch_errors() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("SDL_Init error: %s\n", SDL_GetError());
		exit(1);
	}

	intf->rc = SDL_CreateWindowAndRenderer(intf->settings.SCREEN_WIDTH, intf->settings.SCREEN_HEIGHT, 0, &(intf->window), &(intf->renderer));
	if (intf->rc != 0) {
		SDL_Quit();
		printf("SDL_CreateWindowAndRenderer error: %s\n", SDL_GetError());
		exit(1);
	}
}

void Utils::destroy_window(int code) {
	assert(code == -1 || code == 0 || code == 1);

	SDL_FreeSurface(intf->charset);
	SDL_FreeSurface(intf->screen);
	SDL_DestroyTexture(intf->scrtex);
	SDL_DestroyWindow(intf->window);
	SDL_DestroyRenderer(intf->renderer);
	SDL_Quit();

	if (code != -1) {
		exit(code);
	}
}

Vector Utils::reverse_velocity(Vector velocity) {
	if (velocity.x != -2) velocity.x *= -1;
	if (velocity.y != -2) velocity.y *= -1;
	return velocity;
}