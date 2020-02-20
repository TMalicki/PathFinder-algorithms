#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

//#include "Map.h"

int main()
{
	Game game(sf::Vector2i(10, 10), sf::Vector2f(80.f, 80.f));
	game.run();

	return 0;
}