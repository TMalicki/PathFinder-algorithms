#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>
#include "Map.h"

class Greedy
{
private:

	Map* map;

	int shift;					// distance from center of first node to second one
	bool algorithmRunning;
	float minDist;

	vector<Tile*> openList;		//frontier
	vector<Tile*> closedList;
	vector<Tile*> shortestPath;

	Tile* currentNode;
	Tile* finishNode;
public:

	Greedy(Map& originalMap);
	Greedy(const Greedy& cGreedy);
	Greedy& operator=(const Greedy& aGreedy);

	~Greedy();

	vector<Tile*> getOpenList() { return openList; }
	vector<Tile*> getClosedList() { return closedList; }

	void checkIfAlgorithmIsRunning();
	bool isAlgorithmRunning() { return algorithmRunning; }
	void setAlgorithmRunning(bool val) { algorithmRunning = val; }

	void Run();

	void getPath();

};

#endif