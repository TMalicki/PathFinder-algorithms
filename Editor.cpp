#include "Editor.h"

Editor::Editor(Map* map)
{
	this->map = map;
	editorRunning = true;
	isKeyPressed = false;

	dt = 0.0;
	holdMouseButton = 0.0;
}

Editor::Editor(const Editor& cMap)
{
	this->map = new Map(*cMap.map);

	editorRunning = true;
	isKeyPressed = false;

	holdMouseButton = cMap.holdMouseButton;
	dt = cMap.dt;

}

Editor& Editor::operator=(const Editor& aMap)
{
	if (this != &aMap)
	{
		delete map;
		*this->map = *aMap.map;

		editorRunning = true;
		isKeyPressed = false;

		holdMouseButton = aMap.holdMouseButton;
		dt = aMap.dt;
	}
	return *this;
}

Editor::~Editor()
{
	delete map;
}

void Editor::run(sf::RenderWindow* window, sf::Event& event, Map* map)
{
	dt = clock.restart().asSeconds();

	sf::Vector2f chosenTile = chooseTile(window, map);
	update(window, event, map, chosenTile);
}

void Editor::update(sf::RenderWindow* window, sf::Event& event, Map* map, sf::Vector2f chosenTile)
{
	holdButton();	// check if left button is being pushed for a while
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Enter)
			{
				editorRunning = false;
			}
			if (event.key.code == sf::Keyboard::Escape)
			{
				window->close();
			}
		}

		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
		{
			isKeyPressed = true;
		}

		if (event.type == sf::Event::MouseButtonReleased)
		{
			isKeyPressed = false;
			if (event.mouseButton.button == sf::Mouse::Left && editorRunning == true)
			{
				if (map->getFinishTileExistance() == false) map->setFinishTile(chosenTile);
				else if (map->getStartTileExistance() == false) map->setStartTile(chosenTile);
				else map->setObstacleTiles(chosenTile);		
			}

			if (event.mouseButton.button == sf::Mouse::Right && editorRunning == true)
			{
				map->deleteTile(chosenTile);
			}
		}
	}

	if (holdMouseButton >= 1.5 && map->getStartTileExistance() == true)
	{
		map->setObstacleTiles(chosenTile);
	}
}

void Editor::holdButton()
{
	if (isKeyPressed)
	{
		holdMouseButton += dt;
	}
	else holdMouseButton = 0.0;
}

sf::Vector2f Editor::chooseTile(sf::RenderWindow* window, Map* map)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	std::vector<Tile*>& board = (map->getBoard());

	sf::FloatRect tileBounds;

	sf::Vector2f chosenTile;
	int boardCounter = board.size();

	while (boardCounter--)
	{
		tileBounds = (board)[boardCounter]->getTile().getGlobalBounds();

		if ((mousePos.x > tileBounds.left) && (mousePos.x < tileBounds.left + tileBounds.width)
			&& (mousePos.y > tileBounds.top) && (mousePos.y < tileBounds.top + tileBounds.height))
		{
			(board)[boardCounter]->getTile().setOutlineColor(sf::Color(132, 177, 255, 180));
			chosenTile = (board)[boardCounter]->getTile().getPosition();

			/// building up color changing while holding mouse button
			if (holdMouseButton > 0.6 && map->getStartTileExistance() && (180 * holdMouseButton) / 1.0 < 255) (board)[boardCounter]->getTile().setFillColor(sf::Color(0, 0, 0, ((180 * holdMouseButton) / 1.0)));
		}
		
		else if(board[boardCounter]->getType() == Tile::getNormalTypeName())
		{
			(board)[boardCounter]->getTile().setFillColor(sf::Color::White);
			(board)[boardCounter]->getTile().setOutlineColor(sf::Color::Black);
		}
	}
	return chosenTile;
}

