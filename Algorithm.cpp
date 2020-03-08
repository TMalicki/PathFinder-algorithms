#include "Algorithm.h"

Algorithm::Algorithm(Map& board) : map(&board) /// zrobić zeby ta mapa nie byla przekazywana przez wartosc, bo...
{
	for (int i = 0; i < board.getBoard().size(); i++)
	{
		if (map->getBoard()[i].getType() == Tile::getStartTypeName()) currentNode = &map->getBoard()[i];
		if (map->getBoard()[i].getType() == Tile::getFinishTypeName()) finishNode = &map->getBoard()[i];
	}
	//dt = 0.0;
}

void Algorithm::Begin()
{
	//dt = clock.restart().asSeconds();
	vector<Tile>* Nodes = &(map->getBoard());

	// distance from center of first node to second one
	int shift = (*Nodes)[0].getSize().x;

	openList.push_back(currentNode);
	closedList.push_back(currentNode);

	if (openList.size() > 0)
	{
		bool notCheckedYet = true;
		sf::Vector2f currentPos = currentNode->getPosition();

		openList[0]->getTile().setFillColor(sf::Color::Yellow);
		openList.erase(openList.begin());

		for (int i = 0; i < Nodes->size(); i++)
		{
			if ((*Nodes)[i].getType() == Tile::getNormalTypeName())
			{
				sf::Vector2f checkedPos = (*Nodes)[i].getPosition();

				for (int j = 0; j < closedList.size(); j++)
				{
					if (checkedPos == closedList[j]->getPosition())
					{
						notCheckedYet = false;
					}
				}
				
				if ((checkedPos.x - currentPos.x == 0 && abs(checkedPos.y - currentPos.y) == shift)
					|| (abs(checkedPos.x - currentPos.x) == shift && checkedPos.y - currentPos.y == 0)
					|| (abs(checkedPos.x - currentPos.x) == shift && abs(checkedPos.y - currentPos.y) == shift))
				{
					if (notCheckedYet)
					{
						openList.push_back(&(*Nodes)[i]);
						closedList.push_back(&(*Nodes)[i]);

						closedList.back()->getTile().setFillColor(sf::Color::Yellow);
						openList.back()->getTile().setFillColor(sf::Color::Magenta);
					}
				}
			}
		}
	}
	currentNode = (openList[0]);

	for (int i = 0; i < openList.size(); i++)
	{
		cout << "Numer: " << i << " " << openList[i]->getPosition().x << " " << openList[i]->getPosition().y << endl;
	}

	//double delayTime = 0.0;

	//while (delayTime < 10000.0) delayTime += dt;
}
