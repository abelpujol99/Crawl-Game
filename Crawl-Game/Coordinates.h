#pragma once
class Coordinates {
public:
	int x;
	int y;
	Coordinates() {
		x = 0;
		y = 0;
	}
	Coordinates(int x, int y) {
		this->x = x;
		this->y = y;
	}
};