#include "A_Star.h"

A_Star::A_Star(Map& originalMap) : Algorithm(originalMap), startingNodePosition(getStartingNode()->getPosition())
{

}

void A_Star::run()
{
	if (isAlgorithmRunning() == true)
	{
		int flagTemp = 0;
		flagTemp = getCurrentNodeByFCost();

		checkIfAlgorithmIsRunning();

		vector<Tile*>* openList = &getOpenList();
		openList->erase(openList->begin() + flagTemp);

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

int A_Star::getCurrentNodeByFCost()
{
	int flagTemp = 0;
	if (getCurrentNode() == nullptr) setCurrentNode((getOpenList())[0]);
	else
	{
		flagTemp = findClosestToFinish();
	}
	return flagTemp;
}

int A_Star::findClosestToFinish()
{
	int flagTemp = 0;
	//float fCost = getCurrentNode()->getFCost();
	//float hCost = getCurrentNode()->getHCost();

	float fCost = 100000.0;
	float hCost = 100000.0;

	for (int i = 0; i < getOpenList().size(); i++)
	{
		if (getOpenList()[i]->getFCost() < fCost)
		{
			setCurrentNode(getOpenList()[i]);
			fCost = getOpenList()[i]->getFCost();
			hCost = getOpenList()[i]->getHCost();
			flagTemp = i;
		}
		else if (getOpenList()[i]->getFCost() == fCost)
		{
			if (getOpenList()[i]->getHCost() < fCost)
			{
				setCurrentNode(getOpenList()[i]);
				fCost = getOpenList()[i]->getFCost();
				hCost = getOpenList()[i]->getHCost();
				flagTemp = i;
			}
		}
	}

	return flagTemp;
}

void A_Star::setNeighbourToOpenList(Tile* neighbourNode, Tile* currentNode, bool alreadyChecked)
{
	sf::Vector2f currentPos = currentNode->getPosition();
	sf::Vector2f neighbourPos = neighbourNode->getPosition();

	if ((neighbourPos.x - currentPos.x == 0 && abs(neighbourPos.y - currentPos.y) == getShift())
		|| (abs(neighbourPos.x - currentPos.x) == getShift() && neighbourPos.y - currentPos.y == 0))
		//|| (abs(neighbourPos.x - currentPos.x) == getShift() && abs(neighbourPos.y - currentPos.y) == getShift())) // diagonal movement
	{
		if (alreadyChecked == false)
		{
			///Pitagoras distance on a square grid - hCost
			float hCost = sqrt(pow(neighbourPos.x - getFinishNode()->getPosition().x, 2) + pow(neighbourPos.y - getFinishNode()->getPosition().y, 2));

			neighbourNode->setHCost(hCost);

			// set g cost
			float gCost = abs(startingNodePosition.x - neighbourPos.x) + abs(startingNodePosition.y - neighbourPos.y);

			neighbourNode->setGCost(gCost);

			getOpenList().push_back(neighbourNode);
			getClosedList().push_back(neighbourNode);

			getClosedList().back()->setParent(*currentNode);

			if (getClosedList().back()->getType() == Tile::getNormalTypeName())
			{
				getOpenList().back()->getTile().setFillColor(sf::Color::Magenta);
			}
		}
	}
}