#include "Map.h"

Map::Map(sf::Vector2i numberOfTiles, sf::Vector2f sizeOfTiles) : amountOfTiles(numberOfTiles)
{
	Tile temp(sizeOfTiles);
	sf::Vector2f distance = temp.getSize();
	sf::Vector2f coord = temp.getCoord();

	for (int i = 0; i < numberOfTiles.y; i++)
	{
		for (int j = 0; j < numberOfTiles.x; j++)
		{
			temp.getTile().setPosition(coord.x + (j * distance.x), coord.y + (i * distance.y));
			tile.push_back(temp);
		}
	}
	
}
