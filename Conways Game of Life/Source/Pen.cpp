#include "Pen.h"
#include<iostream>

Pen::Pen(sf::RenderWindow *windowHandle, int tileWidth, int tileHeight) : windowHandle(windowHandle), hasDrawn(false), isDown(false), tileWidth(tileWidth), tileHeight(tileHeight), gridPosLast({0,0}), gridPos({0,0}) {

}

bool Pen::update() {
	gridPos = { sf::Mouse::getPosition(*windowHandle).x / tileWidth, sf::Mouse::getPosition(*windowHandle).y/tileHeight };

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		isDown = true;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		isDown = false;
	}

	if (gridPos.x == gridPosLast.x && gridPos.y == gridPosLast.y) {
		hasDrawn = true;
	} else
		hasDrawn = false;

	if(isDown)
		gridPosLast = gridPos;

	return false;
}

bool Pen::isDrawing() {
	if (isDown && !hasDrawn)
		return true;
	else
		return false;
}