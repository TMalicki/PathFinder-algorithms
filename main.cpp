#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	//Game game(sf::Vector2i(30, 30), sf::Vector2f(30.f, 30.f));
	Game game(sf::Vector2i(15, 15), sf::Vector2f(40.f, 40.f));
	game.run();

	return 0;
}

/// possibility that A* algorithm with diagonal movement is wrong because it should calculate new fCost for old visited nodes (for shortest path)