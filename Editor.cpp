#include "Editor.h"

Editor::Editor(Map* map)
{
	this->map = map;
	editorRunning = true;
}

Editor::Editor(const Editor& cMap)
{
	this->map = new Map(*cMap.map);

	editorRunning = true;

	holdMouseButton = cMap.holdMouseButton;
}

Editor& Editor::operator=(const Editor& aMap)
{
	if (this != &aMap)
	{
		delete map;
		*this->map = *aMap.map;

		editorRunning = true;

		holdMouseButton = aMap.holdMouseButton;
	}
	return *this;
}

Editor::~Editor()
{
	delete map;
}

sf::Vector2f Editor::run(sf::RenderWindow* window, sf::Event& event, Map* map, float holdMouseButton)
{
	this->holdMouseButton = holdMouseButton;

	sf::Vector2f chosenTile = chooseTile(window, map);
	return chosenTile;
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
			if (holdMouseButton > 0.6 && map->getStartTileExistance())
			{
				if (((180 * holdMouseButton) / 1.0) < 255)
				{
					(board)[boardCounter]->getTile().setFillColor(sf::Color(0, 0, 0, ((180 * holdMouseButton) / 1.0))); /// set obstacle tile?
				}
				else
				{
					(board)[boardCounter]->getTile().setFillColor(sf::Color::Black);
				}

				(board)[boardCounter]->setObstacleType();
			}
		}
		
		else if(board[boardCounter]->getType() == Tile::getNormalTypeName())
		{
			(board)[boardCounter]->getTile().setFillColor(sf::Color::White);
			(board)[boardCounter]->getTile().setOutlineColor(sf::Color::Black);
		}
	}
	return chosenTile;
}

