#include "Header.h"

void Settings::print() {
	printf("Screen resolution: %dx%d\n", SCREEN_WIDTH, SCREEN_HEIGHT);
	printf("Max fps: %d\n", MAX_FPS);
	printf("Window title: %s\n", WINDOW_TITLE);
}