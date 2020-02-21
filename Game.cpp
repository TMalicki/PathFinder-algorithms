#include "Game.h"

Game::Game(sf::Vector2i amountOfTiles, sf::Vector2f sizeOfTiles) : map(amountOfTiles, sizeOfTiles)
{
	window = new sf::RenderWindow(sf::VideoMode(amountOfTiles.x * sizeOfTiles.x, amountOfTiles.y * sizeOfTiles.y), "CarAvoid");
	
	window->setFramerateLimit(60);
	window->setTitle("PathFinder");

	closeEditor = false;
}

void Game::run()
{
	while (window->isOpen())
	{
		//int chosenTile;

//		if(closeEditor == false)
		sf::Vector2f chosenTile = highlightTile();

		update(chosenTile);
		draw();
	}
}

void Game::update(sf::Vector2f chosenTile)
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left && closeEditor == false)
			{
				if (map.getFinishTileExistance() == false) map.setFinishTile(chosenTile);
				else if (map.getStartTileExistance() == false) map.setStartTile(chosenTile);
				else if (map.getObstacleTiles().size() < map.getRestOfTiles()) map.setObstacleTiles(chosenTile);
			}
			if (event.mouseButton.button == sf::Mouse::Right && closeEditor == false)
			{
				closeEditor = true;
				cout << "Exit\n";
			}
		}
	}
}

sf::Vector2f Game::highlightTile()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	std::vector<Tile>* board = &(this->map.getNormalTiles());
	sf::FloatRect tileBounds;

	int boardCounter = board->size();
	sf::Vector2f chosenTile;

	while (boardCounter--)
	{
		tileBounds = (*board)[boardCounter].getTile().getGlobalBounds();

		if ((mousePos.x > tileBounds.left) && (mousePos.x < tileBounds.left + tileBounds.width)
			&& (mousePos.y > tileBounds.top) && (mousePos.y < tileBounds.top + tileBounds.height))
		{
			(*board)[boardCounter].getTile().setFillColor(sf::Color(132, 177, 255, 180));
			chosenTile = (*board)[boardCounter].getTile().getPosition();
		}
		else
		{
			(*board)[boardCounter].getTile().setFillColor(sf::Color::White);
		}
	}
	return chosenTile;
}

void Game::draw()
{
	window->clear(sf::Color::White);


	for (int i = 0; i < map.getNormalTiles().size(); i++)
	{
		window->draw(map.getNormalTiles()[i].getTile());
	}
	if (map.getFinishTileExistance()) window->draw(map.getFinishTile().getTile());
	if (map.getStartTileExistance()) window->draw(map.getStartTile().getTile());

	vector<Tile> temp = map.getObstacleTiles();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp.size()) window->draw(temp[i].getTile());
	}


	window->display();
}

