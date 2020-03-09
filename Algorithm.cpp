#include "Algorithm.h"

Algorithm::Algorithm(Map& board) : map(&board) /// zrobić zeby ta mapa nie byla przekazywana przez wartosc, bo...
{
	for (int i = 0; i < board.getBoard().size(); i++)
	{
		if (map->getBoard()[i].getType() == Tile::getStartTypeName()) currentNode = &map->getBoard()[i];
		if (map->getBoard()[i].getType() == Tile::getFinishTypeName()) finishNode = &map->getBoard()[i];
	}

	//dt = clock.restart().asSeconds();
	Nodes = &(map->getBoard());

	// distance from center of first node to second one
	shift = (*Nodes)[0].getSize().x;

	openList.push_back(currentNode);
	closedList.push_back(currentNode);
	//dt = 0.0;
}

bool Algorithm::algorithmRunning()
{
	if (openList.size() > 0)
	{
		if (closedList.back()->getPosition() == finishNode->getPosition())
		{
		
			cout << "KONIEC\n\n\n\n";
			return false;
		
		}
		else return true;
	}
	else return true;
}

void Algorithm::Begin()
{
	if (openList.size() > 0)
	{
		sf::Vector2f currentPos = currentNode->getPosition();
		cout << "Current pos: " << currentPos.x << " " << currentPos.y << endl;
		openList[0]->getTile().setFillColor(sf::Color::Yellow);
		openList.erase(openList.begin());

		for (int i = 0; i < Nodes->size(); i++)
		{
			bool notCheckedYet = true;
			if ((*Nodes)[i].getType() == Tile::getNormalTypeName())
			{
				sf::Vector2f checkedPos = (*Nodes)[i].getPosition();
				cout << "Current checked Pos: " << checkedPos.x << " " << checkedPos.y << endl;
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
						cout << "Pushed: " << (*Nodes)[i].getPosition().x << " " << (*Nodes)[i].getPosition().y << endl;
						closedList.back()->getTile().setFillColor(sf::Color::Yellow);
						openList.back()->getTile().setFillColor(sf::Color::Magenta);
					}
				}
			}
		}
	}
	currentNode = (openList[0]);

	//for (int i = 0; i < openList.size(); i++)
	//{
	//	cout << "Numer: " << i << " " << openList[i]->getPosition().x << " " << openList[i]->getPosition().y << endl;
	//}

	//double delayTime = 0.0;

	//while (delayTime < 10000.0) delayTime += dt;
}
