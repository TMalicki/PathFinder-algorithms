#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game(sf::Vector2i(10, 10), sf::Vector2f(50.f, 50.f));
	game.run();

	

	return 0;
}