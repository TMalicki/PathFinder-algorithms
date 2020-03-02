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

	//Nodes.push_back(map.getFinishTile)
	openList.push_back(currentNode);
	//while (currentNode.getPosition() != finishNode.getPosition())
	//{
		for (int i = 0; i < Nodes->size(); i++)
		{
			sf::Vector2f currentPos = currentNode.getPosition();
			sf::Vector2f checkedPos = (*Nodes)[i].getPosition();

			if ((checkedPos.x - currentPos.x == 0 && abs(checkedPos.y - currentPos.y) == shift)
				|| (abs(checkedPos.x - currentPos.x) == shift && checkedPos.y - currentPos.y == 0)
				|| (abs(checkedPos.x - currentPos.x) == shift && abs(checkedPos.y - currentPos.y) == shift))
			{
				openList.push_back((*Nodes)[i]);
				map->getNormalTiles()[i].getTile().setFillColor(sf::Color::Cyan); /// tu odnosze się do innej mapy niż bym chcial, przez co
				/// nie wyswietla się nic tam gdzie chce
			}
		}
		//if()
		//openList.push_back()
	//}
}
