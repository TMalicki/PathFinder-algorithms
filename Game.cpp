#include "Game.h"

Game::Game(sf::Vector2i amountOfTiles, sf::Vector2f sizeOfTiles)
{
	window = new sf::RenderWindow(sf::VideoMode(amountOfTiles.x * sizeOfTiles.x, amountOfTiles.y * sizeOfTiles.y), "PathFinder");
	map = new Map(amountOfTiles, sizeOfTiles);
	editor = new Editor(map);

	dt = 0.0;
	double delayAlgorithm = 0.0;
	double timeAlgorithmCalculation = 0.0;
	timeShow = false;
}

void Game::run()
{	
	while (window->isOpen())
	{
		dt = clock.restart().asSeconds();

		if (editor->isEditorRunning())
		{
			editor->run(window, event, map);
		}
		else if(editor->isEditorRunning() == false && algorithm != nullptr && algorithm->isAlgorithmRunning() == true)
		{
			delayAlgorithm += dt;
			timeAlgorithmCalculation += dt;
			if (delayAlgorithm > 0.02)
			{
				algorithm->run();
				delayAlgorithm = 0.0;
			}
		}

		else if (algorithm->isAlgorithmRunning() == false && editor->isEditorRunning() == false )
		{
			algorithm->getPath();

			if (timeShow == false)
			{
				cout << "Time: " << timeAlgorithmCalculation << endl;
				delayAlgorithm = 0.0;
				timeAlgorithmCalculation = 0.0;
				timeShow = true;
			}
			update();
		}
	
		if (editor->isEditorRunning() == false && algorithm == nullptr)
		{
			algorithm = new Greedy(*map); /// this should be executed only once
			//algorithm = new BFS(*map);
			delayAlgorithm = 0.0;
			timeAlgorithmCalculation = 0.0;
		}
		draw();
	}
}

void Game::reload()
{
	editor->setEditorRunning(true);
	algorithm->setAlgorithmRunning(false);

	delayAlgorithm = 0.0;
	timeAlgorithmCalculation = 0.0;
	timeShow = false;

	delete algorithm; /// is it needed? memory leak?
	algorithm = nullptr;
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
			if (event.key.code == sf::Keyboard::E)
			{
				reload();
			}
		}
	}
}

void Game::draw()
{
	window->clear(sf::Color::White);
	
	/// draw
	for (int i = 0; i < map->getBoard().size(); i++)
	{
		window->draw(map->getBoard()[i]->getTile());
		if (editor->isEditorRunning() == false)
		{
			window->draw(map->getBoard()[i]->getPosX());
			window->draw(map->getBoard()[i]->getPosY());
		}
	}

	//for (int i = 0; i < algorithm->getOpenList().size(); i++)
	//{
	//	window->draw(algorithm->getOpenList()[i]->getTile());
	//}

	window->display();
}

