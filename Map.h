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
	vector<Tile> tile;
	sf::Vector2i amountOfTiles;
public:
	Map(sf::Vector2i numberOfTiles = { 10, 10 }, sf::Vector2f sizeOfTiles = { 50.f, 50.f });


	void setNumOfTiles(sf::Vector2i numOfTiles) { amountOfTiles = numOfTiles; }
	vector<Tile>& getMap() { return tile; }
};

#endif
