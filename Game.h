#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Editor.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;


	Editor*editor;
	///bool closeEditor;

	///float dt; 
	///sf::Clock clock;
public:
	Game(sf::Vector2i amountOfTiles = { 10,10 }, sf::Vector2f sizeOfTiles = { 50.0f, 50.0f });

	void run();
	void update();
	///void draw();

	///void holdButton();
	///sf::Vector2f highlightTile();
};

#endif