#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Tile
{
private:
	sf::Vector2f size;
	sf::RectangleShape tile;
	float thickness;

	Tile* parent;

public:
	Tile(sf::Vector2f size = { 50.f ,50.f });

	void setSize(sf::Vector2f size) { this->size = size; }
	sf::Vector2f getSize() const { return this->size; }

	sf::RectangleShape& getTile() { return tile; }
	sf::Vector2f getOrigin() { return tile.getOrigin(); }
	sf::Vector2f getPosition() { return tile.getPosition(); }
};


#endif