#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include "Map.h"
#include "Tiles.h"

class Algorithm
{
private:
	Map* map;

	int shift;					// distance from center of first node to second one
	bool algorithmRunning;			

	//float dt;
	//sf::Clock clock;

	vector<Tile*> openList;		//frontier
	vector<Tile*> closedList;
	vector<Tile*> shortestPath;

	Tile* currentNode;
	Tile* finishNode;
	vector<Tile>* board;
public:
	Algorithm(Map& originalMap);

	vector<Tile*> getOpenList() { return openList; }
	vector<Tile*> getClosedList() { return closedList; }

	void checkIfAlgorithmIsRunning();
	bool isAlgorithmRunning() { return algorithmRunning; }
	void Run();

	void getPath();
};

#endif
