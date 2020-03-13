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

void Tile::enablePositions(sf::Font& font)
{
	txtPosX.setFont(font);
	txtPosY.setFont(font);

	txtPosX.setString(std::to_string((int)getPosition().x));
	txtPosY.setString(std::to_string((int)getPosition().y));

	txtPosX.setCharacterSize(16);
	txtPosY.setCharacterSize(16);

	txtPosX.setFillColor(sf::Color::Black);
	txtPosY.setFillColor(sf::Color::Black);

	txtPosX.setPosition(getPosition());
	txtPosX.move(-20, -size.x / 5 - 10);

	txtPosY.setPosition(getPosition());
	txtPosY.move(-20, size.x / 5 - 10);
}

void Tile::enableIteration(sf::Font& font, int i)
{
	txtIteration.setFont(font);

	txtIteration.setString(std::to_string(i));

	txtIteration.setCharacterSize(16);

	txtIteration.setFillColor(sf::Color::Black);

	txtIteration.setPosition(getPosition());
	txtIteration.move(-20, -size.x / 5 - 10);
}
