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
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		
		draw();
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

