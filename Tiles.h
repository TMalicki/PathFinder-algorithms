#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Tile
{
/*
public:
	enum class type
	{
		Normal = 1,
		Finish = 2,
		Start = 3,
		Obstacles = 4
	};
*/
private:
	sf::Vector2f size;
	sf::RectangleShape tile;
	float thickness;
	
	//type tileType;

public:
	Tile(sf::Vector2f size = { 50.f ,50.f });

	void setSize(sf::Vector2f size) { this->size = size; }
	sf::Vector2f getSize() const { return this->size; }

	sf::RectangleShape& getTile() { return tile; }
	sf::Vector2f getCoord() { return tile.getOrigin(); }

	//void setTileType(type tileType) { this->tileType = /*static_cast<type>*/(tileType); }
	//type& getType() { return tileType; }
};


#endif