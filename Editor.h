#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include "Map.h"
#include <SFML/Graphics.hpp>

class Editor
{
private:
	bool editorRunning;

	float dt;
	sf::Clock clock;

	float holdMouseButton;
	bool isKeyPressed;

	Map* map;
public:
	Editor(Map* map);

	void run(sf::RenderWindow* window, sf::Event& event, Map* map);
	void update(sf::RenderWindow* window, sf::Event& event, Map* map, sf::Vector2f chosenTile);

	bool isEditorRunning() { return editorRunning; }
	void setEditorRunning(bool val) { editorRunning = val; }

	void holdButton();
	sf::Vector2f chooseTile(sf::RenderWindow* window, Map* map);
};

#endif
