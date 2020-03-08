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
			board.push_back(temp);
		}
	}

	finishTileExist = false;
	startTileExist = false;
}

/// MAKE FUNCTION FROM THE SAME LINES IN BELOVED FUNCTIONS ------------------------------------------------------------------------------------

void Map::setFinishTile(sf::Vector2f coord)
{
	for (int i = 0; i < board.size() && finishTileExist == false; i++)
	{
		if (coord.x == board[i].getPosition().x && coord.y == board[i].getPosition().y && board[i].getType() == Tile::getNormalTypeName())
		{
			board[i].setFinishType();
			board[i].getTile().setFillColor(sf::Color::Red);
			finishTileExist = true;
		}
	}
}

void Map::setStartTile(sf::Vector2f coord)
{
	for (int i = 0; i < board.size() && startTileExist == false; i++)
	{
		if (coord.x == board[i].getPosition().x && coord.y == board[i].getPosition().y && board[i].getType() == Tile::getNormalTypeName())
		{
			board[i].setStartType();
			board[i].getTile().setFillColor(sf::Color::Green);
			startTileExist = true;
		}
	}
}

void Map::setObstacleTiles(sf::Vector2f coord)
{
	for (int i = 0; i < board.size(); i++)
	{
		if (coord.x == board[i].getPosition().x && coord.y == board[i].getPosition().y && board[i].getType() == Tile::getNormalTypeName())
		{
			board[i].setObstacleType();
			board[i].getTile().setFillColor(sf::Color::Black);
		}
	}
}
void Map::deleteTile(sf::Vector2f coord)
{
	for (int i = 0; i < getBoard().size(); i++)
	{
		if (coord == board[i].getPosition())
		{
			if (board[i].getType() == Tile::getFinishTypeName()) finishTileExist = false;
			else if (board[i].getType() == Tile::getStartTypeName()) startTileExist = false;

			board[i].setNormalType();
		}
	}	
}

/// -----------------------------------------------------------------------------------------------------------------------