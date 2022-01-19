#include "Header.h"

int Queue::size() {
	return end - start + 1;
}

void Queue::push(Bullet a) {
	end++;
	Q[end % Q_SIZE] = a;
}

void Queue::pop() {
	start++;
}

Bullet Queue::front() {
	return Q[start % Q_SIZE];
}