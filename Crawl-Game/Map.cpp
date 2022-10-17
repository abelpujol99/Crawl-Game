#include "Map.h"

Map::Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap) {	

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		std::vector<MapElement*> auxMapElements;

		for (int j = 0; j < MAP_WIDTH; j++)
		{
			MapElement* auxMapElement;
			auxMapElements.push_back(auxMapElement);
		}

		this->_map.push_back(auxMapElements);
	}

	CheckPortalsAvailability(mapOnWorldMapCoordinates, maxWidthAndHeightOfWorldMap);

	system("pause");
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

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if ((i != 0 && i != MAP_HEIGHT - 1) && (j != 0 && j != MAP_WIDTH -1))
			{
				this->_emptyBoxes.push_back(EmptyBox(Coordinates(j, i)));
				EmptyBox* emptyBoxPtr = &_emptyBoxes[_emptyBoxes.size() - 1];
				this->_map[j][i] = emptyBoxPtr;
				continue;
			}
			CreateBlocksOrPortals(Coordinates(j, i), cardinalPortals, portalCounter);
		}
	}
}

void Map::CreateBlocksOrPortals(Coordinates coordinates, std::vector<bool> cardinalPortals, int& portalCounter) {


	if (coordinates.y == floor((MAP_HEIGHT - 1) / 2) || coordinates.x == floor((MAP_WIDTH - 1) /2))
	{
		if (cardinalPortals[portalCounter])
		{
			this->_portals.push_back(Portal(Coordinates(coordinates.x, coordinates.y)));
			Portal* portalPtr = &_portals[_portals.size() - 1];
			this->_map[coordinates.y][coordinates.x] = portalPtr;
		}
		portalCounter++;
		if (cardinalPortals[portalCounter - 1])
		{
			return;
		}
	}
	this->_blocks.push_back(Block(Coordinates(coordinates.x, coordinates.y)));
	Block* blockPtr = &_blocks[_blocks.size() - 1];
	this->_map[coordinates.y][coordinates.x] = blockPtr;
}

void Map::CheckCollision(MapElement* mapElement) {


}

void Map::AddMapElement(MapElement* mapElement) {


}

void Map::Draw(MapElement* mapElements) {

	//TODO: Change Cursor with Console Control and Print mapElements

}

std::vector<std::vector<MapElement*>> Map::GetMapElements() {

	return this->_map;
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
			std::cout << ' ' << std::endl;
		}
	}

}
