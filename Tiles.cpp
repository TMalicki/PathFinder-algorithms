#include "Tiles.h"

Tile::Tile(sf::Vector2f sideSize) : size(sideSize), thickness(-2.0f)
{
	tile.setOutlineThickness(thickness);
	tile.setSize(sf::Vector2f(size.x, size.y));
	tile.setFillColor(sf::Color::White);
	tile.setOutlineColor(sf::Color::Black);
	tile.setOrigin(tile.getSize().x / 2, tile.getSize().y / 2);

	//tileType = type::Normal;
}
