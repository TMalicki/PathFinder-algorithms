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
	algorithmNumber = 0;
}

void Game::run()
{	
	while (window->isOpen())
	{
		dt = clock.restart().asSeconds();

		if (editor->isEditorRunning())
		{
			chosenTile = editor->run(window, event, map, holdMouseButton);
		}
		else
		{
			if (algorithm == nullptr)
			{
				chooseAlgorithm(algorithmNumber);
				delayAlgorithm = 0.0;
				timeAlgorithmCalculation = 0.0;
			}
			else
			{
				if (algorithm->isAlgorithmRunning() == true)
				{
					delayAlgorithm += dt;
					timeAlgorithmCalculation += dt;
					if (delayAlgorithm > 0.02)
					{
						algorithm->run();
						delayAlgorithm = 0.0;
					}
				}
				else
				{
					algorithm->getPath();

					if (timeShow == false)
					{
						cout << "Time: " << timeAlgorithmCalculation << endl;
						delayAlgorithm = 0.0;
						timeAlgorithmCalculation = 0.0;
						timeShow = true;
					}
				}
			}
		}	

		draw();
		update(); 
	}
}

void Game::reload()
{
	editor->setEditorRunning(true);
	algorithm->setAlgorithmRunning(false);

	delayAlgorithm = 0.0;
	timeAlgorithmCalculation = 0.0;
	timeShow = false;

	delete algorithm; 
	algorithm = nullptr;
}

void Game::chooseAlgorithm(int algorithmNumber)
{
	switch (algorithmNumber)
	{
		case 0:
		{
			if (algorithm != nullptr)
			{
				delete algorithm;
				algorithm = nullptr;
			}
			cout << "\nBFS\n";
			algorithm = new BFS(*map);
		}
		break;
		case 1:
		{
			if (algorithm != nullptr)
			{
				delete algorithm;
				algorithm = nullptr;
			}
			cout << "\nGreedy\n";
			algorithm = new Greedy(*map);
		}
		break;
		case 2:
		{
			if (algorithm != nullptr)
			{
				delete algorithm;
				algorithm = nullptr;
			}
			cout << "\nA*\n";
			algorithm = new A_Star(*map);
		}
	}
}

void Game::update()
{
	holdButton();	

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
			if (event.key.code == sf::Keyboard::Enter)
			{
				editor->setEditorRunning(false);
			}
		}
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			isKeyPressed = true;
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			isKeyPressed = false;
			if (event.mouseButton.button == sf::Mouse::Left && editor->isEditorRunning() == true)
			{
				if (map->getFinishTileExistance() == false) map->setFinishTile(chosenTile);
				else if (map->getStartTileExistance() == false) map->setStartTile(chosenTile);
				else map->setObstacleTiles(chosenTile);
			}

			if (event.mouseButton.button == sf::Mouse::Right && editor->isEditorRunning() == true)
			{
				map->deleteTile(chosenTile);
			}
		}

		if (event.type == sf::Event::MouseWheelMoved)
		{
			int mouseDelta = event.mouseWheel.delta;
			if (mouseDelta > 0)
			{
				algorithmNumber += 1;
			}
			else if(mouseDelta < 0)
			{
				algorithmNumber -= 1;
			}

			if (algorithmNumber > 2)
			{
				algorithmNumber = 0;
			}
			else if (algorithmNumber < 0)
			{
				algorithmNumber = 2;
			}

			if (algorithmNumber == 0) cout << "\nBFS\n";
			else if (algorithmNumber == 1) cout << "\nGreedy\n";
			else if (algorithmNumber == 2) cout << "\nA*\n";
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

	window->display();
}

void Game::holdButton()
{
	if (isKeyPressed)
	{
		holdMouseButton += dt;
		cout << holdMouseButton << endl;
	}
	else holdMouseButton = 0.0;
}