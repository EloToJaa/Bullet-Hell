#pragma once

#define NUMBER_OF_IMAGES 8

#include "Header.h"

struct Settings {
public:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 640;
	const int MAX_FPS = 60;
	const char* WINDOW_TITLE = "Bullet Hell";
	const int BG_WIDTH = 3000;
	const int BG_HEIGHT = 1900;

	const char IMAGES[NUMBER_OF_IMAGES][2][MAX_STRING] = {
		{"bg", "bg.bmp"},
		{"left", "left.bmp"},
		{"right", "right.bmp"},
		{"bullet_left", "bullet_left.bmp"},
		{"bullet_right", "bullet_right.bmp"},
		{"bullet_up", "bullet_up.bmp"},
		{"bullet_down", "bullet_down.bmp"},
		{"enemy1", "enemy1.bmp"}
	};

	void print();
};