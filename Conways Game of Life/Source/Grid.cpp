#include "Grid.h"


Grid::Grid(int width = 0, int height = 0) {
	grid.reserve(height);

	for (int i = 0; i <= width; i++) {
		std::vector<Tile*>* vec = new std::vector<Tile*>;
		vec->reserve(width);
		grid.emplace_back(vec);

		for (int j = 0; j <= height; j++) {
			grid[i]->emplace_back(new Tile);
		}
	}
}

void Grid::update() {
	grid[1][2][4]->checkLivingConditions();
}