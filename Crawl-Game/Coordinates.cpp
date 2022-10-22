#include "Coordinates.h"

Coordinates::Coordinates()
{
    this->x = 0;
    this->y = 0;
}

Coordinates::Coordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool Coordinates::CompareXCoordinate(int coordinateXToCompare)
{
    return this->x == coordinateXToCompare;
}

bool Coordinates::CompareYCoordinate(int coordinateYToCompare)
{
    return this->y == coordinateYToCompare;
}

Coordinates* Coordinates::Parse(Json::Value jsonValue)
{
    Coordinates* newCoordinates = new Coordinates();
    try
    {
        newCoordinates->x = jsonValue["PosX"].asInt();
        newCoordinates->y = jsonValue["PosY"].asInt();
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
