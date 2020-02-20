#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

//#include "Map.h"

int main()
{
	Game game(sf::Vector2i(3, 3), sf::Vector2f(200.f, 200.f));
	game.run();

	return 0;
}