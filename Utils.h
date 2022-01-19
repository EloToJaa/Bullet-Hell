#pragma once
#include "Header.h"

struct Utils {
	Interface* intf;

	void catch_errors();

	void destroy_window(int code);

	SDL_Surface* load_bmp(const char file_name[MAX_STRING]);

	void load_bmps();

	int get_key_id(const char key[MAX_STRING]);

	Vector reverse_velocity(Vector velocity);
};