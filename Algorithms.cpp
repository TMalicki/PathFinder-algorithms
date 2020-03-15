#include "Algorithms.h"

Algorithm::Algorithm()
{
	BFS = nullptr;
}

Algorithm::~Algorithm()
{
	delete BFS;
}
