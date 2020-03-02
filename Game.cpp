#include "Game.h"

Game::Game(sf::Vector2i amountOfTiles, sf::Vector2f sizeOfTiles) 
{
	window = new sf::RenderWindow(sf::VideoMode(amountOfTiles.x * sizeOfTiles.x, amountOfTiles.y * sizeOfTiles.y), "PathFinder");
	map = new Map(sf::Vector2i(10, 10), sf::Vector2f(50.f, 50.f));
	editor = new Editor(map);
}

void Game::run()
{
	while (window->isOpen())
	{
		editor->run(window, event, map);
		algorithm = new Algorithm(*map);
		algorithm->Begin();
		update();
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

	for (int i = 0; i < map->getNormalTiles().size(); i++)
		window->draw(map->getNormalTiles()[i].getTile());
	/*
	for (int i = 0; i < map.getNormalTiles().size(); i++)
	{
		window->draw(map.getNormalTiles()[i].getTile());
	}
	if (map.getFinishTileExistance()) window->draw(map.getFinishTile().getTile());
	if (map.getStartTileExistance()) window->draw(map.getStartTile().getTile());

	vector<Tile> temp = map.getObstacleTiles();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp.size()) window->draw(temp[i].getTile());
	}
	*/
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
/*
sf::Vector2f Game::highlightTile()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	std::vector<Tile>* board = &(this->map.getNormalTiles());
	sf::FloatRect tileBounds;

	sf::Vector2f chosenTile;
	int boardCounter = board->size();

	while (boardCounter--)
	{
		tileBounds = (*board)[boardCounter].getTile().getGlobalBounds();

		if ((mousePos.x > tileBounds.left) && (mousePos.x < tileBounds.left + tileBounds.width)
			&& (mousePos.y > tileBounds.top) && (mousePos.y < tileBounds.top + tileBounds.height))
		{
			(*board)[boardCounter].getTile().setFillColor(sf::Color(132, 177, 255, 180));
			chosenTile = (*board)[boardCounter].getTile().getPosition();

			/// building up color changing while holding mouse button
			if (holdMouseButton > 0.6 && map.getStartTileExistance()) (*board)[boardCounter].getTile().setFillColor(sf::Color(0, 0, 0, ((180 * holdMouseButton) / 1.5)));
		}
		else
		{
			(*board)[boardCounter].getTile().setFillColor(sf::Color::White);
		}
	}
	return chosenTile;
}
*/


