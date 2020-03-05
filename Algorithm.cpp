#include "Algorithm.h"

Algorithm::Algorithm(Map& board) : map(&board) /// zrobić zeby ta mapa nie byla przekazywana przez wartosc, bo...
{
	currentNode = map->getStartTile();
	finishNode = map->getFinishTile();
}

void Algorithm::Begin()
{
	vector<Tile>* Nodes = &(map->getNormalTiles());
	int shift = (*Nodes)[0].getSize().x;

	openList.push_back(currentNode);
	closedList.push_back(currentNode);
	
///	while (openList.size() > 0)
///	{
		bool notCheckedYet = true;

		sf::Vector2f currentPos = currentNode.getPosition();
		openList.erase(openList.begin());

		for (int i = 0; i < Nodes->size(); i++)
		{
			sf::Vector2f checkedPos = (*Nodes)[i].getPosition();
			
			for (int j = 0; j < closedList.size(); j++)
			{
				if (checkedPos == closedList[j].getPosition())
				{
					notCheckedYet = false;
				}
			}
			// check if certain tile is neighbour of currentNode
			if ((checkedPos.x - currentPos.x == 0 && abs(checkedPos.y - currentPos.y) == shift)
				|| (abs(checkedPos.x - currentPos.x) == shift && checkedPos.y - currentPos.y == 0)
				|| (abs(checkedPos.x - currentPos.x) == shift && abs(checkedPos.y - currentPos.y) == shift))
			{
				if (notCheckedYet)
				{
					openList.push_back((*Nodes)[i]);
					closedList.push_back((*Nodes)[i]);

					openList.back().getTile().setFillColor(sf::Color::Cyan);
					closedList.back().getTile().setFillColor(sf::Color::Magenta);
				}
			}
		}
		//if()
		//openList.push_back()
///	}
///	for (int i = 0; i < openList.size(); i++)
///	{
///		cout << "Numer: " << i << " " << openList[i].getPosition().x << " " << openList[i].getPosition().y << endl;
///	}
}
