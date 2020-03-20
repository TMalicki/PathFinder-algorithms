#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>
#include "Map.h"

#include "Algorithms.h"

class Greedy : public Algorithm
{
private:

public:
	Greedy(Map& originalMap) : Algorithm(originalMap) {};
	//Greedy(const Greedy& cGreedy);
	//Greedy& operator=(const Greedy& aGreedy);

	virtual ~Greedy() {};

	virtual void run();

	int findClosestToFinish();

	virtual void setNeighbourToOpenList(Tile*, Tile*, bool);
	int getCurrentNodeByHeuristic();
};

#endif