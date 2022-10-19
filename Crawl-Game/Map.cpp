#include "Map.h"

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

	//CreatePointers();
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
				CreateBlocksOrPortals(Coordinates(i, j), cardinalPortals, portalCounter, auxMapElements);
			}			
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Map::CreateBlocksOrPortals(Coordinates coordinates, std::vector<bool> cardinalPortals, int& portalCounter, std::vector<MapElement*>* auxMapElements) {

	if (coordinates.y == floor((MAP_HEIGHT - 1) / 2) || coordinates.x == floor((MAP_WIDTH - 1) /2))
	{
		if (cardinalPortals[portalCounter])
		{
			auxMapElements->at(coordinates.y) = new Portal(Coordinates(coordinates.x, coordinates.y));
		}
		portalCounter++;
		if (cardinalPortals[portalCounter - 1])
		{
			return;
		}
	}
	auxMapElements->at(coordinates.y) = new Block(Coordinates(coordinates.x, coordinates.y));
}

/*void Map::CreatePointers() {

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		std::vector<MapElement*>* auxMapElementPtr = new std::vector<MapElement*>();
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			auxMapElementPtr->push_back(_map[i][j]);
			std::cout << "(" << _map[i][j]->GetCoordinates().x << ", " << _map[i][j]->GetCoordinates().y << ")" << std::flush;
			std::cout << "(" << auxMapElementPtr->at(j)->GetCoordinates().x << ", " << auxMapElementPtr->at(j)->GetCoordinates().y << ")" << std::endl;
		}
		this->_mapPtr->push_back(auxMapElementPtr);
		std::cout << std::endl;
	}
}*/

void Map::CheckCollision(MapElement* mapElement) {


}

void Map::AddMapElement(MapElement* mapElement) {


}

void Map::Draw(MapElement* mapElements) {

	//TODO: Change Cursor with Console Control and Print mapElements
}

std::vector<std::vector<MapElement*>*>* Map::GetMapElements() {

	return this->_mapPtr;
}

void Map::SetMapElementInCurrentMap(MapElement* mapElement) {

	//this->_map[mapElement->GetCoordinates().y][mapElement->GetCoordinates().x] = mapElement;

	//std::vector<MapElement*>* elementToInsertCoordinates = this->_mapPtr->at(mapElement->GetCoordinates().y);
	//elementToInsertCoordinates->at(mapElement->GetCoordinates().x) = _map[mapElement->GetCoordinates().x][mapElement->GetCoordinates().y];

	//MapElement* elementToInsert = elementToInsertCoordinates->at(mapElement->GetCoordinates().x);
	//elementToInsert = _map[mapElement->GetCoordinates().y][mapElement->GetCoordinates().x];
}

void Map::SwapMapElementsInCurrentMap(std::vector<MapElement*> mapElementsToSwap) {

	Coordinates coordinatesToSwap = mapElementsToSwap[0]->GetCoordinates();
	mapElementsToSwap[0]->SetCoordinates(mapElementsToSwap[1]->GetCoordinates());
	mapElementsToSwap[1]->SetCoordinates(coordinatesToSwap);

	for (int i = 0; i < mapElementsToSwap.size(); i++)
	{
		this->SetMapElementInCurrentMap(mapElementsToSwap[i]);
	}


}

void Map::Draw() {

	for (int i = 0; i < _mapPtr->size(); i++)
	{
		for (int j = 0; j < _mapPtr->at(i)->size(); j++)
		{
			std::vector<MapElement*>* auxMapElementCoordinates = _mapPtr->at(i);
			MapElement* auxMapElement = auxMapElementCoordinates->at(j);
			if (auxMapElement != nullptr)
			{
				auxMapElement->Draw();
			}
		}		
		std::cout << std::endl;
	}
}
