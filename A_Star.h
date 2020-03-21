#ifndef A_STAR
#define A_STAR

#include <iostream>
#include "Map.h"

#include "Algorithms.h"

class A_Star : public Algorithm
{
private:
	sf::Vector2f startingNodePosition;

public:
	A_Star(Map& originalMap);
	//A_Star(const A_Star& cA_Star);
	//A_Star& operator=(const A_Star& aA_Star);

	virtual ~A_Star() {};

	virtual void run();

	int getCurrentNodeByFCost();
	int findClosestToFinish();
	virtual void setNeighbourToOpenList(Tile*, Tile*, bool);
};

#endif
