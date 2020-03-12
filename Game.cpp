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
		/// MAKE IT TIME DEPENDENT
		if (editor->editorRunning())
		{
			editor->run(window, event, map);
			algorithm = new Algorithm(*map); // this should be executed only once
		}

		/// MAKE IT TIME DEPENDENT
		else if(algorithm->getAlgorithmRun())
		{
			algorithm->Begin();
			update();
		}

		else if (algorithm->getAlgorithmRun() == false && editor->editorRunning() == false && algorithm->getEndOfAlgorithm() == false)
		{
			algorithm->getPath();
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

