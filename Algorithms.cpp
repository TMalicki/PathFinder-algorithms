#include "Algorithms.h"
#include "Map.h"
#include "BFS.h"

Algorithm::Algorithm(Map& map)
{
	bfs = nullptr;
	this->map = &map;
}

void Algorithm::run_BFS()
{
	bfs = new BFS(*map);
}

Algorithm::~Algorithm()
{
	delete bfs;
}
