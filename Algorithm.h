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
	vector<Tile*> shortestPath;

	Tile* currentNode;
	Tile* finishNode;

	vector<Tile>* Nodes;

	int shift;
	bool algorithmRun;
	bool endOfAlgorithm;
public:
	Algorithm(Map& board);

	vector<Tile*> getOpenList() { return openList; }
	vector<Tile*> getClosedList() { return closedList; }

	void algorithmRunning();
	bool getAlgorithmRun() { return algorithmRun; }
	void Run();

	void getPath();
	bool getEndOfAlgorithm() { return endOfAlgorithm; }
};

#endif
