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
	vector<Tile> normalTile;
	vector<Tile> obstacleTile;

	Tile finishTile;
	Tile startTile;

	sf::Vector2i amountOfTiles;
	
	bool finishTileExist;
	bool startTileExist;
public:
	Map(sf::Vector2i numberOfTiles = { 10, 10 }, sf::Vector2f sizeOfTiles = { 50.f, 50.f });


	void setNumOfTiles(sf::Vector2i numOfTiles) { amountOfTiles = numOfTiles; }
	vector<Tile>& getNormalTiles() { return normalTile; }

	void setFinishTile(int i);
	Tile& getFinishTile() { return finishTile; }
	bool getFinishTileExistance() { return finishTileExist; }

	void setStartTile(int i);
	Tile& getStartTile() { return startTile; }
	bool getStartTileExistance() { return startTileExist; }
};

#endif
