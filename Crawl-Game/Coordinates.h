#pragma once
struct Coordinates {

public:
	int x;
	int y;

	Coordinates() {
		this-> x = 0;
		this-> y = 0;
	}

	Coordinates(int x, int y) {
		
		this->x = x;
		this->y = y;
	}

	bool CompareXCoordinate(int coordinateYToCompare) {
	
		return this->x == coordinateYToCompare;
	}

	bool CompareYCoordinate(int coordinateXToCompare) {
	
		return this->y == coordinateXToCompare;
	}
};