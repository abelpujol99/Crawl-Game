#include "Map.h"

Map::Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap) {	

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		std::vector<MapElement*> auxMapElements;

		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			MapElement* auxMapElement;
			auxMapElements.push_back(auxMapElement);
		}

		this->_map.push_back(auxMapElements);
	}

	CheckPortalsAvailability(mapOnWorldMapCoordinates, maxWidthAndHeightOfWorldMap);

	CreatePointers();
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
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			std::cout << "(" << j << ", " << i << ")" << std::flush;
			if ((i != 0 && i != MAP_HEIGHT - 1) && (j != 0 && j != MAP_WIDTH -1))
			{				
				EmptyBox* emptyBoxPtr = new EmptyBox(Coordinates(j, i));
				this->_map[j][i] = emptyBoxPtr;			
			}
			else
			{
				CreateBlocksOrPortals(Coordinates(j, i), cardinalPortals, portalCounter);
			}			
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Map::CreateBlocksOrPortals(Coordinates coordinates, std::vector<bool> cardinalPortals, int& portalCounter) {

	if (coordinates.y == floor((MAP_HEIGHT - 1) / 2) || coordinates.x == floor((MAP_WIDTH - 1) /2))
	{
		if (cardinalPortals[portalCounter])
		{
			Portal* portalPtr = new Portal(Coordinates(coordinates.x, coordinates.y));
			this->_map[coordinates.x][coordinates.y] = portalPtr;
		}
		portalCounter++;
		if (cardinalPortals[portalCounter - 1])
		{
			return;
		}
	}
	Block* blockPtr = new Block(Coordinates(coordinates.x, coordinates.y)); 
	this->_map[coordinates.x][coordinates.y] = blockPtr;
}

void Map::CreatePointers() {

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		std::vector<MapElement*>* auxMapElementPtr = new std::vector<MapElement*>();
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			auxMapElementPtr->push_back(_map[j][i]);
			std::cout << "(" << auxMapElementPtr->at(j)->GetCoordinates().x << ", " << auxMapElementPtr->at(j)->GetCoordinates().y << ")" << std::flush;
		}
		this->_mapPtr->push_back(auxMapElementPtr);
		std::cout << std::endl;
	}
}

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

	this->_map[mapElement->GetCoordinates().y][mapElement->GetCoordinates().x] = mapElement;
	std::vector<MapElement*>* elementToInsertCoordinates = this->_mapPtr->at(mapElement->GetCoordinates().y);
	elementToInsertCoordinates->at(mapElement->GetCoordinates().x) = _map[mapElement->GetCoordinates().x][mapElement->GetCoordinates().y];

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

	for (int i = 0; i < _map.size(); i++)
	{
		for (int j = 0; j < _map[i].size(); j++)
		{
			if (_map[i][j] != nullptr)
			{
				_map[i][j]->Draw();
			}
		}		
		std::cout << std::endl;
	}
}
