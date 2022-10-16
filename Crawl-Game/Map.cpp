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
}

void Map::CheckPortalsAvailability(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap) {
		
	std::vector<bool> cardinalPortals;
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareYCoordinate(0));
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareXCoordinate(0));
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareXCoordinate(maxWidthAndHeightOfWorldMap.x - 1));
	cardinalPortals.push_back(!mapOnWorldMapCoordinates.CompareYCoordinate(maxWidthAndHeightOfWorldMap.y - 1));

	CreateMapLimits(cardinalPortals);
}

void Map::CreateMapLimits(std::vector<bool> cardinalPortals) {

	int portalCounter = 0;

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			if ((i != 0 && i != MAP_HEIGHT - 1) && (j != 0 && j != MAP_WIDTH -1))
			{
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
			this->_portals.push_back(Coordinates(coordinates.x, coordinates.y));
		}
		portalCounter++;
		return;
	}
	this->_blocks.push_back(Coordinates(coordinates.x, coordinates.y));
}

void Map::CheckCollision(MapElement* mapElement) {


}

void Map::AddMapElement(MapElement* mapElement) {


}

void Map::Draw(MapElement* mapElements) {

	//TODO: Change Cursor with Console Control and Print mapElements

}

std::vector<Portal> Map::GetPortals() {

	return this->_portals;
}

std::vector<Block> Map::GetBlocks() {

	return this->_blocks;
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
