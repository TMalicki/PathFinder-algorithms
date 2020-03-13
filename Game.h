#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Editor.h"
#include "Map.h"
#include "BFS.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	BFS* algorithm;
	Editor* editor;
	Map* map;


	bool timeShow;
	float dt; 
	sf::Clock clock;
	double delayAlgorithm;
	double timeAlgorithmCalculation;
public:
	Game(sf::Vector2i amountOfTiles = { 10,10 }, sf::Vector2f sizeOfTiles = { 50.0f, 50.0f });

	void run();
	void reload();

	void update();
	void draw();

	///void holdButton();
	///sf::Vector2f highlightTile();
};

#endif