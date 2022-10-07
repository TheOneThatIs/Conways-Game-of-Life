#pragma once
#include<vector>
#include"Tile.h"
#include"Pen.h"

class Grid {
private:
	std::vector<std::vector<Tile*>> grid;
	sf::RenderWindow *windowHandle;
	int gridWidth, gridHeight, tileWidth, tileHeight;
	Pen pen;

public:
	Grid(sf::RenderWindow* windowHandle, int gridWidth, int gridHeight, int tileWidth, int tileHeight);

	void clear();
	void update();
	void render();
	void set(sf::Vector2i mousePos);
	void setWindow(sf::RenderWindow &windowHandle);
	
	int getWidth();
	int getHeight();
};