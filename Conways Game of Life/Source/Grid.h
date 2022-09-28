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
	void set(sf::Vector2i mousePos);
	
	float getWidth();
	float getHeight();
};