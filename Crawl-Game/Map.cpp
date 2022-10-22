#include "Map.h"
#include "Coordinates.h"
#include "MapElement.h"
#include "Character.h"
#include "Portal.h"
#include "Block.h"
#include "EmptyBox.h"

Map::Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap) {	

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		std::vector<MapElement*>* auxMapElements = new std::vector<MapElement*>();

		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			MapElement* auxMapElement = new EmptyBox(Coordinates(i, j));
			auxMapElements->push_back(auxMapElement);
		}

		this->_mapPtr->push_back(auxMapElements);
	}

	CheckPortalsAvailability(mapOnWorldMapCoordinates, maxWidthAndHeightOfWorldMap);
}

void Map::CheckPortalsAvailability(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap) {
		
	std::vector<bool> cardinalPortals;
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareYCoordinate(0));
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareXCoordinate(0));
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareXCoordinate(maxWidthAndHeightOfWorldMap.x - 1));
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareYCoordinate(maxWidthAndHeightOfWorldMap.y - 1));

	CreateMap(cardinalPortals);
}

void Map::CreateMap(std::vector<bool> cardinalPortals) {

	int portalCounter = 0;

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		std::vector<MapElement*>* auxMapElements = _mapPtr->at(i);
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			if ((i != 0 && i != MAP_HEIGHT - 1) && (j != 0 && j != MAP_WIDTH -1))
			{
				auxMapElements->at(j) = new EmptyBox(Coordinates(j, i));
			}
			else
			{
				CreateBlocksOrPortals(Coordinates(j, i), cardinalPortals, portalCounter, auxMapElements);
			}			
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Map::CreateBlocksOrPortals(Coordinates coordinates, std::vector<bool> cardinalPortals, int& portalCounter, std::vector<MapElement*>* auxMapElements) {

	if ((coordinates.y == floor(MAP_HEIGHT / 2)) || (coordinates.x == floor(MAP_WIDTH / 2)))
	{
		if (cardinalPortals[portalCounter])
		{
			_portals.push_back(new Portal(Coordinates(coordinates.x, coordinates.y)));
			auxMapElements->at(coordinates.x) = _portals[_portals.size() - 1];
		}
		portalCounter++;
		if (cardinalPortals[portalCounter - 1])
		{
			return;
		}
	}
	auxMapElements->at(coordinates.x) = new Block(Coordinates(coordinates.x, coordinates.y));
}

MapElement** Map::SelectMapElementPointer(Coordinates coordinates) {

	std::vector<MapElement*>* elementToInsertCoordinates = this->_mapPtr->at(coordinates.y);
	return &elementToInsertCoordinates->at(coordinates.x);
}

MapElement* Map::CheckCollision(Coordinates coordinates) {

	return *SelectMapElementPointer(coordinates);
}

//void Map::Draw(MapElement* mapElements) {
//
//	//TODO: Change Cursor with Console Control and Print mapElements
//}

std::vector<std::vector<MapElement*>*>* Map::GetMapElements() {

	return this->_mapPtr;
}

std::vector<Portal*> Map::GetPortals() {

	return _portals;
}

void Map::MoveCharacter(Character* character) {

	SetEmptyBox(character->GetCoordinates());
	character->SetCoordinates(character->GetTargetCoordinatesToMove());

	MapElement** mapElementPtr = SelectMapElementPointer(character->GetCoordinates());
	*mapElementPtr = character;
}

void Map::SetEmptyBox(Coordinates coordinates) {

	MapElement** mapElemenPtrPtr = SelectMapElementPointer(coordinates);
	*mapElemenPtrPtr = new EmptyBox(Coordinates(coordinates.x, coordinates.y));
}

void Map::SetMapElement(MapElement* mapElement) {

	MapElement** mapElementPtrPtr = SelectMapElementPointer(mapElement->GetCoordinates());
	*mapElementPtrPtr = mapElement;
}

void Map::Draw() {

	for (int i = 0; i < _mapPtr->size(); i++)
	{
		for (int j = 0; j < _mapPtr->at(i)->size(); j++)
		{
			MapElement** mapElementPtrPtr = SelectMapElementPointer(Coordinates(j, i));
			if (*mapElementPtrPtr != nullptr)
			{
				mapElementPtrPtr[0]->Draw();
			}
		}		
		std::cout << std::endl;
	}
}
