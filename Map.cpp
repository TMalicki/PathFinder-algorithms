#include "Map.h"

Map::Map(sf::Vector2i numberOfTiles, sf::Vector2f sizeOfTiles) : amountOfTiles(numberOfTiles)
{
	Tile temp(sizeOfTiles);
	sf::Vector2f distance = temp.getSize();
	sf::Vector2f coord = temp.getOrigin();

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

/// MAKE FUNCTION FROM THE SAME LINES IN BELOVED FUNCTIONS ------------------------------------------------------------------------------------

void Map::setFinishTile(sf::Vector2f coord)
{
	for (int i = 0; i < normalTile.size() && finishTileExist == false; i++)
	{
		if (coord.x == normalTile[i].getPosition().x && coord.y == normalTile[i].getPosition().y)
		{
			finishTile = normalTile[i];
			finishTile.getTile().setFillColor(sf::Color::Red);
			normalTile.erase(normalTile.begin() + i);

			finishTileExist = true;
		}
	}
}

void Map::setStartTile(sf::Vector2f coord)
{
	for (int i = 0; i < normalTile.size() && startTileExist == false; i++)
	{
		if (coord.x == normalTile[i].getPosition().x && coord.y == normalTile[i].getPosition().y)
		{
			startTile = normalTile[i];
			startTile.getTile().setFillColor(sf::Color::Green);
			normalTile.erase(normalTile.begin() + i);

			startTileExist = true;
		}
	}
}

void Map::setObstacleTiles(sf::Vector2f coord)
{
	int startingSize = obstacleTile.size();
	for (int i = 0; i < normalTile.size() && obstacleTile.size() == startingSize; i++)
	{
		if (coord.x == normalTile[i].getPosition().x && coord.y == normalTile[i].getPosition().y)
		{
			obstacleTile.push_back(normalTile[i]);
			obstacleTile.back().getTile().setFillColor(sf::Color::Black);
			normalTile.erase(normalTile.begin() + i);
		}
	}
}
void Map::deleteTile(sf::Vector2f coord)
{
	/// try switch maybe?
	sf::Vector2f tempPos = finishTile.getPosition();
	if (coord.x == tempPos.x && coord.y == tempPos.y)
	{
		finishTileExist = false;
		/// delete finishTile; /// maybe with pointer
	}
	tempPos = startTile.getPosition();
	if (coord.x == tempPos.x && coord.y == tempPos.y)
	{
		startTileExist = false;
		/// delete startFile; /// maybe with pointer
	}
	
	for (int i = 0; i < obstacleTile.size(); i++)
	{
		tempPos = obstacleTile[i].getPosition();
		if (coord.x == tempPos.x && coord.y == tempPos.y)
		{
			obstacleTile.erase(obstacleTile.begin() + i);
		}
	}
}
/// -----------------------------------------------------------------------------------------------------------------------