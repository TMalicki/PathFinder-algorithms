#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Tiles.h"

using namespace std;

class Map
{
private:
	vector<Tile> board;
	sf::Font font;
	sf::Vector2i amountOfTiles;

	bool finishTileExist;
	bool startTileExist;
public:
	Map(sf::Vector2i numberOfTiles = { 10, 10 }, sf::Vector2f sizeOfTiles = { 50.f, 50.f });

	void setBoard(Tile& boardTile) { board.push_back(boardTile); }
	vector<Tile>& getBoard() { return board; }

	void deleteTile(sf::Vector2f);

	/// ------------------------
	void setFinishTile(sf::Vector2f);
	bool getFinishTileExistance() { return finishTileExist; }

	/// ------------------------
	void setStartTile(sf::Vector2f);
	bool getStartTileExistance() { return startTileExist; }

	/// -------------------------
	void setObstacleTiles(sf::Vector2f);
};

#endif
