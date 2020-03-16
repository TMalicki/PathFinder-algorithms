#ifndef BFS_H
#define BFS_H

#include <iostream>
#include "Map.h"
#include "Tiles.h"

class BFS
{
private:
	Map* map;

	int shift;					// distance from center of first node to second one
	bool algorithmRunning;			

	vector<Tile*> openList;		//frontier
	vector<Tile*> closedList;
	vector<Tile*> shortestPath;

	Tile* currentNode;
	Tile* finishNode;

public:
	BFS(Map& originalMap);
	BFS(const BFS& cBFS);
	BFS& operator=(const BFS& aBFS);
	
	~BFS();

	vector<Tile*> getOpenList() { return openList; }
	vector<Tile*> getClosedList() { return closedList; }

	void checkIfAlgorithmIsRunning();
	bool isAlgorithmRunning() { return algorithmRunning; }
	void setAlgorithmRunning(bool val) { algorithmRunning = val; }

	void Run();

	void getPath();
};

#endif
