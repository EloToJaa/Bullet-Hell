#include "Header.h"

bool Collider::collision(Collider col) {
	SDL_Rect A = col.rect, B = rect;
	return (A.x + A.w >= B.x && B.x + B.w >= A.x && A.y + A.h >= B.y && B.y + B.h >= A.y);
}

void Collider::init(int x, int y, int w, int h) {
	rect.w = w;
	rect.h = h;
	Vector position;
	position.x = x;
	position.y = y;
	set_position(position);
}

void Collider::set_position(Vector position) {
	int x = position.x;
	int y = position.y;

	rect.x = x - rect.w / 2;
	rect.y = y - rect.h / 2;
}