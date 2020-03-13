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
		if (editor->isEditorRunning())
		{
			editor->run(window, event, map);
			
		}
		/// MAKE IT TIME DEPENDENT
		else if(editor->isEditorRunning() == false && algorithm != nullptr && algorithm->isAlgorithmRunning() == true)
		{
			algorithm->Run();
			update();
		}

		else if (algorithm->isAlgorithmRunning() == false && editor->isEditorRunning() == false )
		{
			algorithm->getPath();
		}

		if (editor->isEditorRunning() == false && algorithm == nullptr)
		{
			algorithm = new Algorithm(*map); /// this should be executed only once
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
		if (editor->isEditorRunning() == false)
		{
			window->draw(map->getBoard()[i].getPosX());
			window->draw(map->getBoard()[i].getPosY());
		}
	}

	//for (int i = 0; i < algorithm->getOpenList().size(); i++)
	//{
	//	window->draw(algorithm->getOpenList()[i]->getTile());
	//}

	window->display();
}

