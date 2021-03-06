﻿#include "Greedy.h"

void Greedy::run()
{
	if (isAlgorithmRunning() == true)
	{
		int flagTemp = 0;
		flagTemp = getCurrentNodeByHeuristic();

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
				alreadyChecked = isNeighbourInsideClosedList(neighbourPos,alreadyChecked);
				setNeighbourToOpenList(neighbourNode, currentNode, alreadyChecked);
			}
		}
	}
}

int Greedy::getCurrentNodeByHeuristic()
{
	int flagTemp = 0;
	if (getCurrentNode() == nullptr) setCurrentNode((getOpenList())[0]);
	else
	{
		flagTemp = findClosestToFinish();
	}
	return flagTemp;
}

int Greedy::findClosestToFinish()
{
	int flagTemp = 0;
	float minDist = 1000.0;

	for (int i = 0; i < getOpenList().size(); i++)
	{
		if (getOpenList()[i]->getHCost() < minDist)
		{
			setCurrentNode(getOpenList()[i]);
			minDist = getOpenList()[i]->getHCost();
			flagTemp = i;
		}
	}

	return flagTemp;
}

void Greedy::setNeighbourToOpenList(Tile* neighbourNode, Tile* currentNode, bool alreadyChecked)
{
	sf::Vector2f currentPos = currentNode->getPosition();
	sf::Vector2f neighbourPos = neighbourNode->getPosition();

	if ((neighbourPos.x - currentPos.x == 0 && abs(neighbourPos.y - currentPos.y) == getShift())
		|| (abs(neighbourPos.x - currentPos.x) == getShift() && neighbourPos.y - currentPos.y == 0))
		//|| (abs(neighbourPos.x - currentPos.x) == getShift() && abs(neighbourPos.y - currentPos.y) == getShift())) // diagonal movement
	{
		if (alreadyChecked == false)
		{
			///Pitagoras distance on a square grid
			//float actualDistance = abs(neighbourPos.x - getFinishNode()->getPosition().x) + abs(neighbourPos.y - getFinishNode()->getPosition().y);
			float hCost = sqrt(pow(neighbourPos.x-getFinishNode()->getPosition().x,2) + pow(neighbourPos.y - getFinishNode()->getPosition().y,2));
			neighbourNode->setHCost(hCost);

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

