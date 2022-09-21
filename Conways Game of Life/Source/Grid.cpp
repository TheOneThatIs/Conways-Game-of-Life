#include "Grid.h"


Grid::Grid(int width = 100, int height = 100) {
	grid.reserve(height);

	for (int i = 0; i <= height; i++) {
		grid.emplace_back(std::vector<Tile*>());
		grid.back().reserve(width);

		for (int j = 0; j <= width; j++) {
			grid[i].emplace_back(new Tile());
		}
	}
}

void Grid::clear() {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			delete grid[i][j];
		}
	}
}

void Grid::update() {
	grid[1][2]->checkLivingConditions();
}