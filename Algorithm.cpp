#include "Algorithm.h"

Algorithm::Algorithm(Map& board) : map(&board) 
{
	for (int i = 0; i < board.getBoard().size(); i++)
	{
		if (map->getBoard()[i].getType() == Tile::getStartTypeName())
		{
			currentNode = &map->getBoard()[i];
		}
		if (map->getBoard()[i].getType() == Tile::getFinishTypeName())
		{
			finishNode = &map->getBoard()[i];
		}
	}
	algorithmRun = true;

	//dt = clock.restart().asSeconds();
	Nodes = &(map->getBoard());

	// distance from center of first node to second one
	shift = (*Nodes)[0].getSize().x;

	openList.push_back(currentNode);
	closedList.push_back(currentNode);
	
	if(board.getFinishTileExistance())
	cout << " \n\n\n" << finishNode->getPosition().x << " " << finishNode->getPosition().y << " \n\n\n";
	//dt = 0.0;
}

void Algorithm::algorithmRunning()
{
	//currentNode->getPosition();
	if (openList.size() > 0 && currentNode->getPosition() == finishNode->getPosition())
	{
		algorithmRun = false;
	}
}

void Algorithm::Begin()
{
		sf::Vector2f currentPos = currentNode->getPosition();
		///cout << "Current pos: " << currentPos.x << " " << currentPos.y << endl;
		if (openList[0]->getType() == Tile::getNormalTypeName())
		{
			openList[0]->getTile().setFillColor(sf::Color::Yellow);
		}
		openList.erase(openList.begin());

		for (int i = 0; i < Nodes->size(); i++)
		{
			bool notCheckedYet = true;
			auto temp = (*Nodes)[i].getType();

			if (temp == Tile::getNormalTypeName() || temp == Tile::getFinishTypeName()) 
			{
				sf::Vector2f checkedPos = (*Nodes)[i].getPosition();
				///cout << "Current checked Pos: " << checkedPos.x << " " << checkedPos.y << endl;
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
						///cout << "Pushed: " << (*Nodes)[i].getPosition().x << " " << (*Nodes)[i].getPosition().y << endl;

						if (closedList.back()->getType() == Tile::getNormalTypeName())
						{
							closedList.back()->getTile().setFillColor(sf::Color::Yellow);
							openList.back()->getTile().setFillColor(sf::Color::Magenta);
						}
					}
				}
			}
		}
	currentNode = (openList[0]);

	algorithmRunning();
	//cout << "Closed List: " << currentNode->getPosition().x << " " << currentNode->getPosition().y << " \n";
	//for (int i = 0; i < openList.size(); i++)
	//{
	//	cout << "Numer: " << i << " " << openList[i]->getPosition().x << " " << openList[i]->getPosition().y << endl;
	//}

	//double delayTime = 0.0;

	//while (delayTime < 10000.0) delayTime += dt;
}
