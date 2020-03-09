#include "Game.h"

Game::Game(sf::Vector2i amountOfTiles, sf::Vector2f sizeOfTiles)
{
	window = new sf::RenderWindow(sf::VideoMode(amountOfTiles.x * sizeOfTiles.x, amountOfTiles.y * sizeOfTiles.y), "PathFinder");
	map = new Map(amountOfTiles, sizeOfTiles);
	editor = new Editor(map);
}

void Game::run()
{
	while (window->isOpen())
	{
		if (editor->editorRunning())
		{
			editor->run(window, event, map);
			algorithm = new Algorithm(*map); // to słabe bo za każdym razem podczas edytora sie wywołuje, a mogło by tylko raz po skonczeniu edytora
		}

		else if(algorithm->algorithmRunning())
		{
			algorithm->Begin();
			update();
		}

		draw();
	}
}

void Game::update()
{
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape) window->close();
		}
	}
}

void Game::draw()
{
	window->clear(sf::Color::White);
	
	/// draw
	for (int i = 0; i < map->getBoard().size(); i++)
	{
		window->draw(map->getBoard()[i].getTile());
	}

	//for (int i = 0; i < algorithm->getOpenList().size(); i++)
	//{
	//	window->draw(algorithm->getOpenList()[i]->getTile());
	//}

	window->display();
}



///
/*
void Game::holdButton()
{
	if (isKeyPressed)
	{
		holdMouseButton += dt;
	}
	else holdMouseButton = 0.0;
}
*/
///


