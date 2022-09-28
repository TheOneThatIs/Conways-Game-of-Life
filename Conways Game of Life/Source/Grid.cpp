#include "Grid.h"
#include<iostream>

Grid::Grid(int width = 10, int height = 10) : TILE_WIDTH(50), TILE_HEIGHT(50), width(width), height(height) {
	grid.reserve(height);

	for (int i = 0; i < height; i++) {
		grid.emplace_back(std::vector<Tile*>());
		grid.back().reserve(width);

		for (int j = 0; j < width; j++) {
			grid[i].emplace_back(new Tile());
			grid[i].back()->setPos(j * TILE_WIDTH, i * TILE_HEIGHT);
			grid[i].back()->getShape()->setSize({TILE_WIDTH, TILE_HEIGHT});
		}
	}
}

void Grid::clear() {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			delete grid[i][j];
		}
		grid[i].clear();
	}
	grid.clear();
}

void Grid::update() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grid[1][2]->checkLivingConditions();
		}
	}
}

void Grid::render(sf::RenderWindow *windowHandle) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//std::cout << "Drawing: [" << i << "], [" << j << "]" << std::endl;
			windowHandle->draw(*grid[i][j]->getShape());
		}
	}
}

float Grid::getWidth() { return width * TILE_WIDTH; }
float Grid::getHeight() { return height * TILE_HEIGHT; }