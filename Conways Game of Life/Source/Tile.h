#pragma once
#include<vector>

class Tile {
private:

public:
	bool isAlive, willDie;

public:
	Tile();
	
	void checkLivingConditions();
};