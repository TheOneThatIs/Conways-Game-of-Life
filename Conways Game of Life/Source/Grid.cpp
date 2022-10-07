#include "Grid.h"
#include<iostream>

Grid::Grid(sf::RenderWindow* windowHandle, int gridWidth = 10, int gridHeight = 10, int tileWidth = 50, int tileHeight = 50) : gridWidth(gridWidth), gridHeight(gridHeight), tileWidth(tileWidth), tileHeight(tileHeight), pen(windowHandle, tileWidth, tileHeight), isRunning(false), stepsToSimulate(0) {
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
	if (stepsToSimulate > 0 || stepsToSimulate == -1) {
		std::cout << "Simulating!\n";
		
		for (int y = 0; y < gridHeight; y++) {
			for (int x = 0; x < gridWidth; x++) {
				// Check top layer
				if ((x - 1 < grid[0].size()) && (y - 1 < grid.size()) && x >= 0 && y >= 0)
					if (grid[x - 1][y - 1]->isAlive)
						grid[x][y]->numNeighboursAlive++;
				if ((x < grid[0].size()) && (y - 1 < grid.size()) && x >= 0 && y >= 0)
					if (grid[x][y - 1]->isAlive)
						grid[x][y]->numNeighboursAlive++;
				if ((x + 1 < grid[0].size()) && (y - 1 < grid.size()) && x >= 0 && y >= 0)
					if (grid[x + 1][y - 1]->isAlive)
						grid[x][y]->numNeighboursAlive++;

				// Check middle layer
				if ((x - 1 < grid[0].size()) && (y < grid.size()) && x >= 0 && y >= 0)
					if (grid[x - 1][y]->isAlive)
						grid[x][y]->numNeighboursAlive++;
				if ((x + 1 < grid[0].size()) && (y < grid.size()) && x >= 0 && y >= 0)
					if (grid[x + 1][y]->isAlive)
						grid[x][y]->numNeighboursAlive++;

				// Check bottom layer
				if ((x - 1 < grid[0].size()) && (y + 1 < grid.size()) && x >= 0 && y >= 0)
					if (grid[x - 1][y + 1]->isAlive)
						grid[x][y]->numNeighboursAlive++;
				if ((x < grid[0].size()) && (y + 1 < grid.size()) && x >= 0 && y >= 0)
					if (grid[x][y + 1]->isAlive)
						grid[x][y]->numNeighboursAlive++;
				if ((x + 1 < grid[0].size()) && (y + 1 < grid.size()) && x >= 0 && y >= 0)
					if (grid[x + 1][y + 1]->isAlive)
						grid[x][y]->numNeighboursAlive++;
			}
		}

		for (int i = 0; i < gridHeight; i++) {
			for (int j = 0; j < gridWidth; j++) {
				switch (grid[i][j]->numNeighboursAlive) {
					case 0:
					case 1:
						grid[i][j]->willDie = true;
						break;
					case 2:
						if (!grid[i][j]->isAlive) {
							grid[i][j]->willDie = false;
							break;
						}
					case 3:
						if (grid[i][j]->isAlive) {
							grid[i][j]->willDie = false;
							break;
						}
						else {
							grid[i][j]->willResurrect = true;
							break;
						}
							
					default:
						grid[i][j]->willDie = true;
						break;
				}
				std::cout << "[" << i << "][" << j << "] = " << grid[i][j]->numNeighboursAlive << "\t";
				grid[i][j]->numNeighboursAlive = 0;
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < gridHeight; i++) {
			for (int j = 0; j < gridWidth; j++) {
				if (grid[i][j]->willDie) {
					grid[i][j]->isAlive = false;
					grid[i][j]->willDie = false;
				}
				if (grid[i][j]->willResurrect) {
					grid[i][j]->isAlive = true;
					grid[i][j]->willResurrect = false;
				}
			}
		}

		if(stepsToSimulate != -1)
			stepsToSimulate--;
	}
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
		if (pen.gridPos.y < grid.size() && pen.gridPos.x < grid[0].size()) {
			grid[pen.gridPos.y][pen.gridPos.x]->isAlive = !grid[pen.gridPos.y][pen.gridPos.x]->isAlive;
		}
	}
}

void Grid::setWindow(sf::RenderWindow &windowHandle) {
	this->windowHandle = &windowHandle;
}

void Grid::runSimulation() {
	if (stepsToSimulate == 0)
		stepsToSimulate = -1;
	else if(stepsToSimulate == -1)
		stepsToSimulate = 0;
}

int Grid::getWidth() { return gridWidth * tileWidth; }
int Grid::getHeight() { return gridHeight * tileHeight; }