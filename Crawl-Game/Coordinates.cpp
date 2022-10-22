#include "Coordinates.h"

Coordinates::Coordinates() : x (0), y (0) {
}

Coordinates::Coordinates(int x, int y) : x (x), y (y) {
}

Coordinates Coordinates::SubtractCoordinates(Coordinates coordinatesToSubtract) {

	Coordinates result;
	result.x = coordinatesToSubtract.x - this->x;
	result.y = coordinatesToSubtract.y - this->y;
	return result;
}

void Coordinates::MultiplyCoordinateX(int numberToMultiply) {

	this->x *= numberToMultiply;
}

void Coordinates::MultiplyCoordinateY(int numberToMultiply) {

	this->y *= numberToMultiply;
}

void Coordinates::AddCoordinates(Coordinates coordinatesToAdd) {

    this->x += coordinatesToAdd.x;
    this->y += coordinatesToAdd.y;
}

bool Coordinates::CompareXCoordinate(int coordinateYToCompare) {

	return this->x == coordinateYToCompare;
}

bool Coordinates::CompareYCoordinate(int coordinateXToCompare) {

	return this->y == coordinateXToCompare;
}
Coordinates* Coordinates::Parse(Json::Value jsonValue)
{
    Coordinates* newCoordinates = new Coordinates();
    try
    {
        newCoordinates->y = jsonValue["PosY"].asInt();
        newCoordinates->x = jsonValue["PosX"].asInt();
        return newCoordinates;
    }
    catch (const std::exception&)
    {
        delete newCoordinates;
        return nullptr;
    }
}
Json::Value Coordinates::ToJsonValue()
{
    Json::Value jsonValue;
    jsonValue["PosX"] = x;
    jsonValue["PosY"] = y;

    return jsonValue;
}
