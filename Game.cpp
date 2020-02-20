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
		highlightTile();
		draw();
	}
}

void Game::highlightTile()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	std::vector<Tile> board = map.getMap();

	for (int i = 0; i < board.size(); i++)
	{
		sf::FloatRect tileBounds = board[i].getTile().getGlobalBounds();
		/*
		using std::cout; using std::endl;

		cout << mousePos.x << " " << mousePos.y << " " <<
			board[1].getTile().getGlobalBounds().left << " " << board[1].getTile().getGlobalBounds().left + board[1].getTile().getGlobalBounds().width << " " <<
			board[1].getTile().getGlobalBounds().top << " " << board[1].getTile().getGlobalBounds().top + board[1].getTile().getGlobalBounds().height << endl;
		*/
		if ((mousePos.x > tileBounds.left) && (mousePos.x < tileBounds.left + tileBounds.width)
			&& (mousePos.y > tileBounds.top) && (mousePos.y < tileBounds.top + tileBounds.height))
		{
			board[i].getTile().setFillColor(sf::Color(132, 177, 255, 180));
		}
		else
		{
			board[i].getTile().setFillColor(sf::Color::Red);
			board[i].getTile().setOutlineColor(sf::Color::Green);
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

