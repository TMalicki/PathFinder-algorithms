#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include "Map.h"
#include <SFML/Graphics.hpp>

class Editor
{
private:
	Map map;
	bool closeEditor;

	float dt;
	sf::Clock clock;

	float holdMouseButton;
	bool isKeyPressed;
public:
	Editor(sf::Vector2i amountOfTiles = { 10,10 }, sf::Vector2f sizeOfTiles = { 50.0f, 50.0f });
	void run(sf::RenderWindow* window, sf::Event& event);

	void update(sf::RenderWindow* window, sf::Event& event, sf::Vector2f chosenTile);
	void draw(sf::RenderWindow* window);

	void holdButton();
	sf::Vector2f highlightTile(sf::RenderWindow* window);
};

#endif
