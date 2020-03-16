#include "BFS.h"

BFS::BFS(Map& originalMap) : map(&originalMap)
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

	//dt = clock.restart().asSeconds();
	//dt = 0.0;
}

BFS::BFS(const BFS& cBFS)
{
	*map = *(cBFS.map);
	
	*currentNode = *(cBFS.currentNode);

	*finishNode = *(cBFS.finishNode);

	for (int i = 0; i < openList.size(); i++)
	{
		openList.push_back(cBFS.openList[i]);
	}
	
	for (int i = 0; i < closedList.size(); i++)
	{
		closedList.push_back(cBFS.closedList[i]);
	}

	for (int i = 0; i < shortestPath.size(); i++)
	{
		shortestPath.push_back(cBFS.shortestPath[i]);
	}

	shift = cBFS.shift;
	algorithmRunning = cBFS.algorithmRunning;
}


BFS& BFS::operator=(const BFS& aBFS)
{
	if (this != &aBFS)
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

		map = aBFS.map;
		
		openList = aBFS.openList;
		closedList = aBFS.closedList;
		shortestPath = aBFS.shortestPath;
		currentNode = aBFS.currentNode;
		finishNode = aBFS.finishNode;

		shift = aBFS.shift;
		algorithmRunning = aBFS.algorithmRunning;
	}
	return *this;
}


BFS::~BFS()
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

void BFS::checkIfAlgorithmIsRunning()
{
	/// end algorithm if finishNode is achieved or there is nothing inside openList
	if (openList.size() == 0 || currentNode->getPosition() == finishNode->getPosition())
	{
		algorithmRunning = false;
	}
}

void BFS::Run()
{
	if (algorithmRunning == true)
	{
		currentNode = (openList[0]);

		checkIfAlgorithmIsRunning();

		openList.erase(openList.begin());

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

void BFS::getPath()
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

//	endOfAlgorithm = true;
}
