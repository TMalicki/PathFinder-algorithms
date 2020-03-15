#include "Map.h"

Map::Map(sf::Vector2i numberOfTiles, sf::Vector2f sizeOfTiles) : amountOfTiles(numberOfTiles)
{
	Tile temp(sizeOfTiles);
	int distance = temp.getSize().x;
	sf::Vector2f coord = temp.getOrigin();

	//if (!font.loadFromFile("fonts/QuiteMagical.ttf"))
	//{
	//	std::cout << "Error with font.\n";
	//}

	for (int i = 0; i < numberOfTiles.y; i++)
	{
		for (int j = 0; j < numberOfTiles.x; j++)
		{
			board.push_back(new Tile(sizeOfTiles));
			board.back()->getTile().setPosition(coord.x + (j * distance), coord.y + (i * distance));
		//	board.back().enablePositions(font);
		}
	}

	finishTileExist = false;
	startTileExist = false;
}

Map::Map(const Map& cMap)
{
	for (int i = 0; i < cMap.board.size(); i++)
	{
		board.push_back(cMap.board[i]);
	}
	font = cMap.font;
	amountOfTiles = cMap.amountOfTiles;

	finishTileExist = cMap.finishTileExist;
	startTileExist = cMap.startTileExist;
}

Map& Map::operator=(const Map& aMap)
{
	if (this != &aMap)
	{
		for (int i = 0; i < aMap.board.size(); i++)
		{
			delete board[i];
			board[i] = nullptr;
		}
		for (int i = 0; i < aMap.board.size(); i++)
		{
			board[i] = aMap.board[i];
		}

		font = aMap.font;
		amountOfTiles = aMap.amountOfTiles;

		finishTileExist = aMap.finishTileExist;
		startTileExist = aMap.startTileExist;
	}
	return *this;
}

Map::~Map()
{
	for (int i = 0; i < board.size(); i++)
	{
		delete board[i];
		board[i] = nullptr;
	}
}

/// MAKE FUNCTION FROM THE SAME LINES IN BELOVED FUNCTIONS ------------------------------------------------------------------------------------

void Map::setFinishTile(sf::Vector2f coord)
{
	for (int i = 0; i < board.size() && finishTileExist == false; i++)
	{
		if (coord == board[i]->getPosition() && board[i]->getType() == Tile::getNormalTypeName())
		{
			board[i]->setFinishType();
			board[i]->getTile().setFillColor(sf::Color::Red);
			finishTileExist = true;
		}
	}
}

void Map::setStartTile(sf::Vector2f coord)
{
	for (int i = 0; i < board.size() && startTileExist == false; i++)
	{
		if (coord == board[i]->getPosition() && board[i]->getType() == Tile::getNormalTypeName())
		{
			board[i]->setStartType();
			board[i]->getTile().setFillColor(sf::Color::Green);
			startTileExist = true;
		}
	}
}

void Map::setObstacleTiles(sf::Vector2f coord)
{
	for (int i = 0; i < board.size(); i++)
	{
		if (coord == board[i]->getPosition() && board[i]->getType() == Tile::getNormalTypeName())
		{
			board[i]->setObstacleType();
			board[i]->getTile().setFillColor(sf::Color::Black);
		}
	}
}
void Map::deleteTile(sf::Vector2f coord)
{
	for (int i = 0; i < getBoard().size(); i++)
	{
		if (coord == board[i]->getPosition())
		{
			if (board[i]->getType() == Tile::getFinishTypeName()) finishTileExist = false;
			else if (board[i]->getType() == Tile::getStartTypeName()) startTileExist = false;

			board[i]->setNormalType();
		}
	}	
}

/// -----------------------------------------------------------------------------------------------------------------------