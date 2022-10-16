#include "Map.h"

Map::Map(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap) {	

	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		std::vector<char> auxCharVector;

		for (int j = 0; j < MAP_WIDTH; j++)
		{
			auxCharVector.push_back(' ');
		}

		this->_map.push_back(auxCharVector);
	}

	CheckPortalsAvailability(mapOnWorldMapCoordinates, maxWidthAndHeightOfWorldMap);
}

void Map::CheckPortalsAvailability(Coordinates mapOnWorldMapCoordinates, Coordinates maxWidthAndHeightOfWorldMap) {
		
	std::vector<bool> cardinalPortals;
	cardinalPortals.push_back(mapOnWorldMapCoordinates.CompareXCoordinate(0));
	cardinalPortals.push_back(mapOnWorldMapCoordinates.CompareXCoordinate(maxWidthAndHeightOfWorldMap.x - 1));
	cardinalPortals.push_back(mapOnWorldMapCoordinates.CompareYCoordinate(0));
	cardinalPortals.push_back(mapOnWorldMapCoordinates.CompareYCoordinate(maxWidthAndHeightOfWorldMap.y - 1));

	CreatePortalsOrWalls(cardinalPortals);
}

void Map::CreatePortalsOrWalls(std::vector<bool> cardinalPortals) {

	if (cardinalPortals[0])
	{	
		this->_portals.push_back(Portal(Coordinates(0, (MAP_HEIGHT - 1) / 2)));
	}
	else
	{
		this->_walls.push_back(Wall(Coordinates(0, (MAP_HEIGHT - 1) / 2)));
	}
	
	if (cardinalPortals[1])
	{
		this->_portals.push_back(Portal(Coordinates(MAP_WIDTH - 1, (MAP_HEIGHT - 1) / 2)));
	}
	else
	{
		this->_walls.push_back(Wall(Coordinates(MAP_WIDTH - 1, (MAP_HEIGHT - 1) / 2)));
	}
	
	if (cardinalPortals[2])
	{
		this->_portals.push_back(Portal(Coordinates(0, (MAP_WIDTH - 1) / 2)));
	}
	else
	{
		this->_walls.push_back(Wall(Coordinates(0, (MAP_WIDTH - 1) / 2)));
	}
	
	if (cardinalPortals[3])
	{
		this->_portals.push_back(Portal(Coordinates(MAP_HEIGHT - 1, (MAP_WIDTH - 1) / 2)));
	}
	else
	{
		this->_walls.push_back(Wall(Coordinates(MAP_HEIGHT - 1, (MAP_WIDTH - 1) / 2)));
	}
}

void Map::CheckCollision(MapElementCoordinates* malElements) {


}

void Map::Draw(MapElementCoordinates* mapElements) {

	//TODO: Change Cursor with Console Control and Print mapElements

}
