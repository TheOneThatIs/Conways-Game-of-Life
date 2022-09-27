#include "Tile.h"
#include<vector>

Tile::Tile() : tile(), isAlive(false), willDie(false) {
	tile.setFillColor(sf::Color(255, 255, 255, 255));
	tile.setOutlineColor(sf::Color::Magenta);
	tile.setOutlineThickness(1);
}

void Tile::checkLivingConditions() {

}

void Tile::setPos(float x, float y) {
	tile.setPosition({ x, y });
}

sf::RectangleShape* Tile::getShape() {
	return &tile;
}