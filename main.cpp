﻿#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	Game game(sf::Vector2i(10, 10), sf::Vector2f(50.f, 50.f));
	game.run();

	return 0;
}


/// wyswietlic closedList i pokazać rodzica każdego elementu, powinno być coś w stylu:
// 1 el -> rodzic = 0 el
// 2 el -> rodzic = 1 el
// 3 el -> rodzic = 2 el etc.