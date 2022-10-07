#include "Grid.h"
#include<iostream>

Grid::Grid(sf::RenderWindow* windowHandle, int gridWidth = 10, int gridHeight = 10, int tileWidth = 50, int tileHeight = 50) : gridWidth(gridWidth), gridHeight(gridHeight), tileWidth(tileWidth), tileHeight(tileHeight), pen(windowHandle, tileWidth, tileHeight) {
	grid.reserve(gridHeight);

	for (int i = 0; i < gridHeight; i++) {
		grid.emplace_back(std::vector<Tile*>());
		grid.back().reserve(gridWidth);

		for (int j = 0; j < gridWidth; j++) {
			grid[i].emplace_back(new Tile());
			grid[i].back()->setPos(j * tileWidth, i * tileHeight);
			grid[i].back()->getShape()->setSize({(float)tileWidth, (float)tileHeight});
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
	for (int i = 0; i < gridHeight; i++) {
		for (int j = 0; j < gridWidth; j++) {
			grid[1][2]->checkLivingConditions();
		}
	}

	pen.update();
}

void Grid::render() {
	for (int i = 0; i < gridHeight; i++) {
		for (int j = 0; j < gridWidth; j++) {
			if(grid[i][j]->isAlive) {
				windowHandle->draw(*grid[i][j]->getShape());
			}
		}
	}
}

void Grid::set(sf::Vector2i mousePos) {
	pen.update();
	if (pen.isDrawing()) {
		if(pen.gridPos.y < grid.size() && pen.gridPos.x < grid[0].size())
			grid[pen.gridPos.y][pen.gridPos.x]->isAlive = !grid[pen.gridPos.y][pen.gridPos.x]->isAlive;
	}
}

void Grid::setWindow(sf::RenderWindow &windowHandle) {
	this->windowHandle = &windowHandle;
}

int Grid::getWidth() { return gridWidth * tileWidth; }
int Grid::getHeight() { return gridHeight * tileHeight; }