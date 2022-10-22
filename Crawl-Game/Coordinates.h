#pragma once
#include <utility>
struct Coordinates {

public:
	int x;
	int y;

	Coordinates();
	Coordinates(int x, int y);
	Coordinates SubtractCoordinates(Coordinates coordinatesToSubtract);
	void MultiplyCoordinateX(int numberToMultiply);
	void MultiplyCoordinateY(int numberToMultiply);
	bool CompareXCoordinate(int coordinateYToCompare);
	bool CompareYCoordinate(int coordinateXToCompare);
};