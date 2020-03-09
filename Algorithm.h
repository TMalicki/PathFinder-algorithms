#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include "Map.h"
#include "Tiles.h"

class Algorithm
{
private:
	Map* map;

	float dt;
	sf::Clock clock;

	vector<Tile*> openList;
	vector<Tile*> closedList;

	Tile* currentNode;
	Tile* finishNode;

	vector<Tile>* Nodes;

	int shift;
public:
	Algorithm(Map& board);

	vector<Tile*> getOpenList() { return openList; }
	vector<Tile*> getClosedList() { return closedList; }

	bool algorithmRunning();
	void Begin();
};

#endif
