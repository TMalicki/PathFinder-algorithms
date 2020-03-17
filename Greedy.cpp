#include "Greedy.h"

Greedy::Greedy(Map& originalMap) : map(&originalMap)
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
	}
	shift = (*board)[0]->getSize().x;
	closedList.push_back(openList.back());

	minDist = 1000.0;
}

Greedy::Greedy(const Greedy& cGreedy)
{
	*map = *(cGreedy.map);

	*currentNode = *(cGreedy.currentNode);

	*finishNode = *(cGreedy.finishNode);

	for (int i = 0; i < openList.size(); i++)
	{
		openList.push_back(cGreedy.openList[i]);
	}

	for (int i = 0; i < closedList.size(); i++)
	{
		closedList.push_back(cGreedy.closedList[i]);
	}

	for (int i = 0; i < shortestPath.size(); i++)
	{
		shortestPath.push_back(cGreedy.shortestPath[i]);
	}

}

Greedy& Greedy::operator=(const Greedy& aGreedy)
{
	if (this != &aGreedy)
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

		map = aGreedy.map;

		openList = aGreedy.openList;
		closedList = aGreedy.closedList;
		shortestPath = aGreedy.shortestPath;
		currentNode = aGreedy.currentNode;
		finishNode = aGreedy.finishNode;

		shift = aGreedy.shift;
		algorithmRunning = aGreedy.algorithmRunning;
	}
	return *this;
}

Greedy::~Greedy()
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

void Greedy::checkIfAlgorithmIsRunning()
{
	/// end algorithm if finishNode is achieved or there is nothing inside openList
	if (currentNode->getPosition() == finishNode->getPosition())
	{
		algorithmRunning = false;
	}
}

void Greedy::Run()
{
	/// powinno być tak ze każdy dostaje parametr distance, ale w kolejnej kolejce jako pierwszy idzie ten ktory ma najwieksze priority
	if (algorithmRunning == true)
	{
		int flagTemp = 0;

		if (currentNode == nullptr) currentNode = (openList[0]);
		else
		{
			float minDist = 1000.0;
			for (int i = 0; i < openList.size(); i++)
			{
				if (openList[i]->getDistance() < minDist)
				{
					currentNode = openList[i];
					minDist = openList[i]->getDistance();
					flagTemp = i;
				}
			}
		}	

		checkIfAlgorithmIsRunning();

		openList.erase(openList.begin() + flagTemp);

		sf::Vector2f currentPos = currentNode->getPosition();

		/// for not coloring starting and finishing tiles
		if (currentNode->getType() == Tile::getNormalTypeName())
		{
			currentNode->getTile().setFillColor(sf::Color(173, 166, 164, 255));
		}
		//cout << "CURRENT POSITION: " << currentPos.x << " " << currentPos.y << "\n\n";

		auto board = &map->getBoard();

		/// currentNode neighbours iterator
		for (int i = 0; i < board->size() && algorithmRunning == true; i++)
		{
			bool alreadyChecked = false;

			auto neighbourNode = &(*board)[i];
			auto neighbourType = (*board)[i]->getType();
			sf::Vector2f neighbourPos = (*board)[i]->getPosition();

			if ((neighbourType == Tile::getNormalTypeName() || neighbourType == Tile::getFinishTypeName()))
			{
				//cout << "CHECKED POSITION: " << neighbourPos.x << " " << neighbourPos.y << "\n";

				/// check if checking position is not already inside closedList (alreadyChecked)
				for (int j = 0; j < closedList.size(); j++)
				{
					if (neighbourPos == closedList[j]->getPosition())
					{
						alreadyChecked = true;
					}
				}

				if ((neighbourPos.x - currentPos.x == 0 && abs(neighbourPos.y - currentPos.y) == shift)
					|| (abs(neighbourPos.x - currentPos.x) == shift && neighbourPos.y - currentPos.y == 0))
					//|| (abs(checkedPos.x - currentPos.x) == shift && abs(checkedPos.y - currentPos.y) == shift)) // diagonal movement
				{
					if (alreadyChecked == false)
					{
						///Manhattan distance on a square grid
						//float actualDistance = sqrt(pow(((*neighbourNode)->getPosition().x - finishNode->getPosition().x), 2) + pow(((*neighbourNode)->getPosition().x - finishNode->getPosition().x), 2));
						float actualDistance = abs((*neighbourNode)->getPosition().x - finishNode->getPosition().x) + abs((*neighbourNode)->getPosition().y - finishNode->getPosition().y);
						(*neighbourNode)->setDistance(actualDistance);
						
						openList.push_back(*neighbourNode);
						closedList.push_back(*neighbourNode);
						//cout << "Pushed: " << neighbourPos.x << " " << neighbourPos.y;

						closedList.back()->setParent(*currentNode);

						//cout << "   PARENT -> " << closedList.back()->getParent()->getPosition().x << " " << closedList.back()->getParent()->getPosition().y << "\n";

						if (closedList.back()->getType() == Tile::getNormalTypeName())
						{
							//closedList.back()->getTile().setFillColor(sf::Color(173,166,164,255));
							openList.back()->getTile().setFillColor(sf::Color::Magenta);
						}
					}
				}
			}
		}
	}
}

void Greedy::getPath()
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
