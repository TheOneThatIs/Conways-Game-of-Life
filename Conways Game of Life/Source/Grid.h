#pragma once
#include<vector>
#include"Tile.h"

class Grid {
private:
	std::vector<std::vector<Tile*>> grid;
	const float TILE_WIDTH, TILE_HEIGHT;
	float width, height;

public:
	Grid(int width, int height);

	void clear();
	void update();
	void render(sf::RenderWindow *windowHandle);
	
	float getWidth();
	float getHeight();
};