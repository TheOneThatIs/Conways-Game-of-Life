#include "Tile.h"
#include<vector>

Tile::Tile() : tile(), isAlive(false), willDie(false) {
	tile.setFillColor(sf::Color(255, 255, 255, 255));
	tile.setOutlineColor(sf::Color::Magenta);
	tile.setOutlineThickness(1);
}

void Tile::checkLivingConditions() {

}

void Tile::setPos(int x, int y) {
	tile.setPosition({ (float)x, (float)y });
}

sf::RectangleShape* Tile::getShape() {
	return &tile;
}