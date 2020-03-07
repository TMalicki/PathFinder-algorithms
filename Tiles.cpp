#include "Tiles.h"

const string Tile::obstacle = "obstacle";
const string Tile::finish = "finish";
const string Tile::start = "start";
const string Tile::normal = "normal";

Tile::Tile(sf::Vector2f sideSize) : size(sideSize), thickness(-2.0f)
{	
	tile.setOutlineThickness(thickness);
	tile.setSize(sf::Vector2f(size.x, size.y));
	tile.setFillColor(sf::Color::White);
	tile.setOutlineColor(sf::Color::Black);
	tile.setOrigin(tile.getSize().x / 2, tile.getSize().y / 2);

	setNormalType();
}
