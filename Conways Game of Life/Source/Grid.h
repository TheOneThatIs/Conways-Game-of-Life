#pragma once
#include<vector>
#include"Tile.h"
#include"Pen.h"

class Grid {
private:
	std::vector<std::vector<Tile*>> grid;
	float gridWidth, gridHeight, tileWidth, tileHeight;
	sf::RenderWindow *windowHandle;
	Pen pen;

public:
	Grid(float gridWidth, float gridHeight, float tileWidth, float tileHeight);

	void clear();
	void update();
	void render();
	void set(sf::Vector2i mousePos);
	void setWindow(sf::RenderWindow &windowHandle);
	
	float getWidth();
	float getHeight();
};