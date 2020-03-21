#ifndef EDITOR_H
#define EDITOR_H

#include <iostream>
#include "Map.h"
#include <SFML/Graphics.hpp>

class Editor
{
private:
	bool editorRunning;

//	float dt;
//	sf::Clock clock;

//	float holdMouseButton;
//	bool isKeyPressed;

	Map* map;
public:
	Editor(Map* map);
	Editor(const Editor& cMap);
	Editor& operator=(const Editor& aMap);

	~Editor();

	sf::Vector2f run(sf::RenderWindow* window, sf::Event& event, Map* map, float holdMouseButton);

	bool isEditorRunning() { return editorRunning; }
	void setEditorRunning(bool val) { editorRunning = val; }

	sf::Vector2f chooseTile(sf::RenderWindow* window, Map* map, float holdMouseButton);
};

#endif
