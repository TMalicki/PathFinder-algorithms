#include "Algorithms.h"
#include "Map.h"

Algorithm::Algorithm(Map& originalMap) : map(&originalMap)
{
	algorithmRunning = true;
	auto board = &(map->getBoard());

	/// set up -> put startNode inside openList and closedList, get finishNode 
	for (int i = 0; i < originalMap.getBoard().size(); i++)
	{
		if ((*board)[i]->getType() == Tile::getStartTypeName())
		{
			openList.push_back((*board)[i]);
		}
		if (map->getBoard()[i]->getType() == Tile::getFinishTypeName())
		{
			finishNode = (*board)[i];
		}
		if (map->getBoard()[i]->getType() == Tile::getStartTypeName())
		{
			startingNode = (*board)[i];
		}
	}
	shift = (*board)[0]->getSize().x;
	closedList.push_back(openList.back());
}

Algorithm::Algorithm(const Algorithm* cAlgorithm)
{
	*map = *(cAlgorithm->map);

	*currentNode = *(cAlgorithm->currentNode);

	*finishNode = *(cAlgorithm->finishNode);

	for (int i = 0; i < openList.size(); i++)
	{
		openList.push_back(cAlgorithm->openList[i]);
	}

	for (int i = 0; i < closedList.size(); i++)
	{
		closedList.push_back(cAlgorithm->closedList[i]);
	}

	for (int i = 0; i < shortestPath.size(); i++)
	{
		shortestPath.push_back(cAlgorithm->shortestPath[i]);
	}

	shift = cAlgorithm->shift;
	algorithmRunning = cAlgorithm->algorithmRunning;
}

Algorithm& Algorithm::operator=(const Algorithm* aAlgorithm)
{
	if (this != aAlgorithm)
	{
		map = nullptr;
		currentNode = nullptr;
		finishNode = nullptr;

		for (int i = 0; i < openList.size(); i++)
		{
			openList[i] = nullptr;
		}
		for (int i = 0; i < closedList.size(); i++)
		{
			closedList[i] = nullptr;
		}
		for (int i = 0; i < shortestPath.size(); i++)
		{
			shortestPath[i] = nullptr;
		}

		map = aAlgorithm->map;
		
		openList = aAlgorithm->openList;
		closedList = aAlgorithm->closedList;
		shortestPath = aAlgorithm->shortestPath;
		currentNode = aAlgorithm->currentNode;
		finishNode = aAlgorithm->finishNode;

		shift = aAlgorithm->shift;
		algorithmRunning = aAlgorithm->algorithmRunning;
	}
	return *this;
}

Algorithm::~Algorithm()
{
	map = nullptr;
	currentNode = nullptr;
	finishNode = nullptr;

	for (int i = 0; i < openList.size(); i++)
	{
		openList[i] = nullptr;
	}
	for (int i = 0; i < closedList.size(); i++)
	{
		closedList[i] = nullptr;
	}
	for (int i = 0; i < shortestPath.size(); i++)
	{
		shortestPath[i] = nullptr;
	}
}

void Algorithm::checkIfAlgorithmIsRunning()
{
	/// end algorithm if finishNode is achieved or there is nothing inside openList
	if (openList.size() == 0 || currentNode->getPosition() == finishNode->getPosition())
	{
		algorithmRunning = false;
	}
}

void Algorithm::getPath()
{
	shortestPath.push_back(currentNode);

	while (shortestPath.back()->getType() != Tile::getStartTypeName())
	{
		//cout << shortestPath.back()->getPosition().x << " " << shortestPath.back()->getPosition().y << "\n";
		shortestPath.push_back(shortestPath.back()->getParent());
	}
	//while ((*Nodes).back().getType() != Tile::getStartTypeName()) {

	for (int i = 0; i < shortestPath.size(); i++)
	{
		//cout << shortestPath[i]->getPosition().x << " " << shortestPath[i]->getPosition().y << "\n";
		if (shortestPath[i]->getType() == Tile::getNormalTypeName())
		{
			shortestPath[i]->getTile().setFillColor(sf::Color::Blue);
		}
	}
}

bool Algorithm::isNeighbourInsideClosedList(sf::Vector2f neighbourPos,bool& alreadyChecked)
{
	for (int j = 0; j < closedList.size(); j++)
	{
		if (neighbourPos == closedList[j]->getPosition())
		{
			alreadyChecked = true;
		}
	}
	return alreadyChecked;
}
