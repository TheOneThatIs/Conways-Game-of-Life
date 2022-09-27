#pragma once
#include<vector>
#include<SFML/Graphics.hpp>

class Tile {
private:
	sf::RectangleShape tile;

public:
	bool isAlive, willDie;

public:
	Tile();
	
	void checkLivingConditions();
	void setPos(float x, float y);
	sf::RectangleShape* getShape();
};