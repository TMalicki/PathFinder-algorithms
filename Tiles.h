#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using std::string;

class Tile
{
private:
	sf::Vector2f size;
	sf::RectangleShape tile;
	float thickness;
	float gCost;
	float hCost;	// distance

	sf::Text txtPosX;
	sf::Text txtPosY;
	sf::Text txtIteration;

	Tile* parent;

	string type;
	const static string finish;
	const static string start;
	const static string obstacle;
	const static string normal;

public:
	Tile(sf::Vector2f size = { 50.f ,50.f });
	Tile(const Tile& cTile);
	Tile& operator=(const Tile& aTile);

	~Tile();

	void setSize(sf::Vector2f size) { this->size = size; }
	sf::Vector2f getSize() const { return this->size; }

	sf::RectangleShape& getTile() { return tile; }
	sf::Vector2f getOrigin() { return tile.getOrigin(); }
	sf::Vector2f getPosition() { return tile.getPosition(); }
	void setColor(sf::Color color) { tile.setFillColor(color); }
	void setHCost(float hCost) { this->hCost = hCost; }
	float getHCost() { return this->hCost; }
	void setGCost(float gCost) { this->gCost = gCost; }
	float getGCost() { return this->gCost; }

	float getFCost() { return gCost + hCost; }

	void setNormalType() { type = normal; }
	void setObstacleType() { type = obstacle; }
	void setFinishType() { type = finish; }
	void setStartType() { type = start; }

	void setParent(Tile& child) { parent = &child; }
	Tile* getParent() { return parent; }

	string getType() { return type; }
	static string getNormalTypeName() { return normal; }
	static string getFinishTypeName() { return finish; }
	static string getStartTypeName() { return start; }
	static string getObstacleTypeName() { return obstacle; }

	void enablePositions(sf::Font&);
	void enableIteration(sf::Font&, int);
	sf::Text& getPosX() { return txtPosX; }
	sf::Text& getPosY() { return txtPosY; }
};


#endif