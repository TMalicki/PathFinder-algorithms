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


/// wyswietlic closedList i pokazać rodzica każdego elementu, powinno być coś w stylu:
// 1 el -> rodzic = 0 el
// 2 el -> rodzic = 1 el
// 3 el -> rodzic = 2 el etc.