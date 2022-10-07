#pragma once
#include<vector>
#include<SFML/Graphics.hpp>

class Tile {
private:
	sf::RectangleShape tile;

public:
	int numNeighboursAlive;
	bool isAlive, willDie, willResurrect;

public:
	Tile();
	
	bool checkLivingConditions();
	void setPos(int x, int y);
	sf::RectangleShape* getShape();
};