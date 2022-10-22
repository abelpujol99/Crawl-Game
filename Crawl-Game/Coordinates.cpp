#include "Coordinates.h"

Coordinates::Coordinates() : x (0), y (0) {
}

Coordinates::Coordinates(int x, int y) : x (x), y (y) {
}

Coordinates Coordinates::SubtractCoordinates(Coordinates coordinatesToSubtract) {

	Coordinates result;
	result.x = this->x - coordinatesToSubtract.x;
	result.y = this->y - coordinatesToSubtract.y;
	return result;
}

void Coordinates::MultiplyCoordinateX(int numberToMultiply) {

	this->x *= numberToMultiply;
}

void Coordinates::MultiplyCoordinateY(int numberToMultiply) {

	this->y *= numberToMultiply;
}

bool Coordinates::CompareXCoordinate(int coordinateYToCompare) {

	return this->x == coordinateYToCompare;
}

bool Coordinates::CompareYCoordinate(int coordinateXToCompare) {

	return this->y == coordinateXToCompare;
}