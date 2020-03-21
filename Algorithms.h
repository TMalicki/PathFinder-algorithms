#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include "Map.h"

class Algorithm
{
private:
	Map* map;

	int shift;
	bool algorithmRunning;

	vector<Tile*> openList;		//frontier
	vector<Tile*> closedList;
	vector<Tile*> shortestPath;

	Tile* currentNode;
	Tile* finishNode;
	Tile* startingNode;
public:
	Algorithm(Map& originalMap);
	Algorithm(const Algorithm* cAlgorithm);
	Algorithm& operator=(const Algorithm* aBFS);
	virtual ~Algorithm();

	int getShift() { return shift; }
	
	vector<Tile*>& getOpenList() { return openList; }
	vector<Tile*>& getClosedList() { return closedList; }
	Tile* getCurrentNode() { return currentNode; }
	void setCurrentNode(Tile* currentNode) { this->currentNode = currentNode; }
	Tile* getFinishNode() { return finishNode; }
	Tile* getStartingNode() { return startingNode; }
	Map* getMap() { return map; }

	bool isAlgorithmRunning() { return algorithmRunning; }
	void checkIfAlgorithmIsRunning();
	void setAlgorithmRunning(bool val) { algorithmRunning = val; }
	bool isNeighbourInsideClosedList(sf::Vector2f, bool&);

	void getPath();

	virtual void setNeighbourToOpenList(Tile*, Tile*, bool) = 0;
	virtual void run() = 0;

	
};


#endif