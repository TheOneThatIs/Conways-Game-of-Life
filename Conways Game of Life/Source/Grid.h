#pragma once
#include<vector>
#include"Tile.h"

class Grid {
private:
	std::vector<std::vector<Tile*>*> grid;

public:
	Grid(int width, int height);

	void update();

};