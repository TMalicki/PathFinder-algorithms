#include "Game.h"

Game::Game(sf::Vector2i amountOfTiles, sf::Vector2f sizeOfTiles) : map(amountOfTiles, sizeOfTiles)
{
	window = new sf::RenderWindow(sf::VideoMode(amountOfTiles.x * sizeOfTiles.x, amountOfTiles.y * sizeOfTiles.y), "CarAvoid");
	
	window->setFramerateLimit(60);
	window->setTitle("PathFinder");
}

void Game::run()
{
	while (window->isOpen())
	{
		int chosenTile = highlightTile();

		update(chosenTile);
		draw();
	}
}

void Game::update(int chosenTile)
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (map.getFinishTileExistance() == false) map.setFinishTile(chosenTile);
				else if (map.getStartTileExistance() == false) map.setStartTile(chosenTile);
			}
		}
	}
}

int Game::highlightTile()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	std::vector<Tile>* board = &(this->map.getNormalTiles());
	sf::FloatRect tileBounds;

	int boardCounter = board->size();
	int chosenTile = 0;
	while (boardCounter--)
	{
		tileBounds = (*board)[boardCounter].getTile().getGlobalBounds();

		if ((mousePos.x > tileBounds.left) && (mousePos.x < tileBounds.left + tileBounds.width)
			&& (mousePos.y > tileBounds.top) && (mousePos.y < tileBounds.top + tileBounds.height))
		{
			(*board)[boardCounter].getTile().setFillColor(sf::Color(132, 177, 255, 180));
			chosenTile = boardCounter;
			//setFinish(boardCounter);
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
	if(map.getFinishTileExistance()) window->draw(map.getFinishTile().getTile());
	if (map.getStartTileExistance()) window->draw(map.getStartTile().getTile());
	window->display();
}

