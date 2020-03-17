#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include "BFS.h"


class Algorithm
{
private:
	BFS* bfs;
	Map* map;
public:
	Algorithm(Map& map);

	void run_BFS();

	~Algorithm();
};


#endif