#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	Map map;
	bool closeEditor;
public:
	Game(sf::Vector2i amountOfTiles = { 10,10 }, sf::Vector2f sizeOfTiles = { 50.0f, 50.0f });

	void run();
	void update(sf::Vector2f);
	void draw();

	sf::Vector2f highlightTile();
};

#endif