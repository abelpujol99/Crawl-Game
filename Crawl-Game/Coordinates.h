#pragma once
#include "json/json.h"
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
	void AddCoordinates(Coordinates coordinates);
	bool CompareXCoordinate(int coordinateYToCompare);
	bool CompareYCoordinate(int coordinateXToCompare);
	static Coordinates* Parse(Json::Value jsonValue);
	Json::Value ToJsonValue();
};