#pragma once
#include "Header.h"

#define Q_SIZE 1000

struct Queue {
	int start = 0, end = -1;
	Bullet Q[Q_SIZE];

	int size();

	void push(Bullet a);

	void pop();

	Bullet front();
};