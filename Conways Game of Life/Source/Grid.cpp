#include "Grid.h"
#include<iostream>

Grid::Grid(float gridWidth = 10, float gridHeight = 10, float tileWidth = 50, float tileHeight = 50) : gridWidth(gridWidth), gridHeight(gridHeight), tileWidth(tileWidth), tileHeight(tileHeight), pen(windowHandle) {
	grid.reserve(gridHeight);

	for (int i = 0; i < gridHeight; i++) {
		grid.emplace_back(std::vector<Tile*>());
		grid.back().reserve(gridWidth);

		for (int j = 0; j < gridWidth; j++) {
			grid[i].emplace_back(new Tile());
			grid[i].back()->setPos(j * tileWidth, i * tileHeight);
			grid[i].back()->getShape()->setSize({tileWidth, tileHeight});
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
	grid[mousePos.y / tileHeight][mousePos.x / tileWidth ]->isAlive = !grid[mousePos.y / tileHeight][mousePos.x / tileWidth]->isAlive;
}

void Grid::setWindow(sf::RenderWindow &windowHandle) {
	this->windowHandle = &windowHandle;
}

float Grid::getWidth() { return gridWidth * tileWidth; }
float Grid::getHeight() { return gridHeight * tileHeight; }