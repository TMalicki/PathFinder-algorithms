#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include "Map.h"
#include "Tiles.h"

class Algorithm
{
private:
	Map* map;

	vector<Tile> openList;
	vector<Tile> closedList;

	Tile currentNode;
	Tile finishNode;
public:
	Algorithm(Map& board);
	void Begin();
};

#endif
