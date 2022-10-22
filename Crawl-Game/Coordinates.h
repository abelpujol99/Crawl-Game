#pragma once
#include "json/json.h"
struct Coordinates {

public:
	int x;
	int y;

	Coordinates();
	Coordinates(int x, int y);

	bool CompareXCoordinate(int coordinateXToCompare);
	bool CompareYCoordinate(int coordinateYToCompare);

	static Coordinates* Parse(Json::Value jsonValue);
	Json::Value ToJsonValue();
};