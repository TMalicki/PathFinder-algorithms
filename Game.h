#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Editor.h"
#include "Map.h"
#include "Algorithms.h"
#include "BFS.h"
#include "Greedy.h"
#include "A_Star.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Event event;

	Algorithm* algorithm;
	Editor* editor;
	Map* map;

	bool timeShow;
	float dt; 
	sf::Clock clock;
	double delayAlgorithm;
	double timeAlgorithmCalculation;
	int algorithmNumber;

	float holdMouseButton;
	bool isKeyPressed;

	sf::Vector2f chosenTile;
public:
	Game(sf::Vector2i amountOfTiles = { 10,10 }, sf::Vector2f sizeOfTiles = { 50.0f, 50.0f });

	void run();
	void reload();
	void chooseAlgorithm(int);

	void update();
	void draw();
	void holdButton();
};

#endif