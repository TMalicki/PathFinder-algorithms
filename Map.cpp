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
			normalTile.push_back(temp);
		}
	}
	
	finishTileExist = false;
	startTileExist = false;
}

void Map::setFinishTile(int i)
{
	finishTile = normalTile[i]; 
	finishTile.getTile().setFillColor(sf::Color::Red);
	normalTile.erase(normalTile.begin() + i);

	finishTileExist = true;
}

void Map::setStartTile(int i)
{
	startTile = normalTile[i];
	startTile.getTile().setFillColor(sf::Color::Blue);
	normalTile.erase(normalTile.begin() + i);

	startTileExist = true;
}
