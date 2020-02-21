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
		
		highlightTile();
		draw();
	}
}

void Game::update()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
}

void Game::highlightTile()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	std::vector<Tile>* board = &(this->map.getMap());
	sf::FloatRect tileBounds;

	int boardCounter = board->size();
	while (boardCounter--)
	{
		tileBounds = (*board)[boardCounter].getTile().getGlobalBounds();

		if ((mousePos.x > tileBounds.left) && (mousePos.x < tileBounds.left + tileBounds.width)
			&& (mousePos.y > tileBounds.top) && (mousePos.y < tileBounds.top + tileBounds.height))
		{
			(*board)[boardCounter].getTile().setFillColor(sf::Color(132, 177, 255, 180));
		}
		else
		{
			(*board)[boardCounter].getTile().setFillColor(sf::Color::White);
		}
	}
}

void Game::draw()
{
	window->clear(sf::Color::White);
	for (int i = 0; i < map.getMap().size(); i++)
	{
		window->draw(map.getMap()[i].getTile());
	}
	window->display();
}

