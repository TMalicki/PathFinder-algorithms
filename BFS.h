#ifndef BFS_H
#define BFS_H

#include <iostream>
#include "Map.h"

#include "Algorithms.h"

class BFS : public Algorithm
{
private:
	
public:
	BFS(Map& originalMap) : Algorithm(originalMap) {}
	//BFS(const BFS& cBFS);
	//BFS& operator=(const BFS& aBFS);
	
	virtual ~BFS() {};

	virtual void run();

	virtual void setNeighbourToOpenList(Tile*, Tile*, bool);
};

#endif
