#include "BFS.h"


void BFS::run()
{
	if (isAlgorithmRunning() == true)
	{
		vector<Tile*>* openList = &getOpenList();
		setCurrentNode((*openList)[0]);

		checkIfAlgorithmIsRunning();

		openList->erase(openList->begin());

		Tile* currentNode = getCurrentNode();
		sf::Vector2f currentPos = currentNode->getPosition();

		/// for not coloring starting and finishing tiles
		if (currentNode->getType() == Tile::getNormalTypeName())
		{
			currentNode->getTile().setFillColor(sf::Color(173, 166, 164, 255));
		}
	
		auto board = &(getMap()->getBoard());
		
		/// currentNode neighbours iterator
		for (int i = 0; i < board->size() && isAlgorithmRunning() == true; i++)
		{
			bool alreadyChecked = false;
			auto neighbourNode = (*board)[i];
			auto neighbourType = (*board)[i]->getType();
			sf::Vector2f neighbourPos = (*board)[i]->getPosition();

			if ((neighbourType == Tile::getNormalTypeName() || neighbourType == Tile::getFinishTypeName()))
			{
				/// check if checking position is not already inside closedList (alreadyChecked)
				alreadyChecked = isNeighbourInsideClosedList(neighbourPos, alreadyChecked);
				setNeighbourToOpenList(neighbourNode, currentNode, alreadyChecked);
			}
		}
	}
}

void BFS::setNeighbourToOpenList(Tile* neighbourNode, Tile* currentNode, bool alreadyChecked)
{
	sf::Vector2f currentPos = currentNode->getPosition();
	sf::Vector2f neighbourPos = neighbourNode->getPosition();

	if ((neighbourPos.x - currentPos.x == 0 && abs(neighbourPos.y - currentPos.y) == getShift())
		|| (abs(neighbourPos.x - currentPos.x) == getShift() && neighbourPos.y - currentPos.y == 0))
		//|| (abs(neighbourPos.x - currentPos.x) == getShift() && abs(neighbourPos.y - currentPos.y) == getShift())) // diagonal movement
	{
		if (alreadyChecked == false)
		{
			getOpenList().push_back(neighbourNode);
			getClosedList().push_back(neighbourNode);

			getClosedList().back()->setParent(*currentNode);

			if (getClosedList().back()->getType() == Tile::getNormalTypeName())
			{
				//closedList.back()->getTile().setFillColor(sf::Color(173,166,164,255));
				getOpenList().back()->getTile().setFillColor(sf::Color::Magenta);
			}
		}
	}
}

