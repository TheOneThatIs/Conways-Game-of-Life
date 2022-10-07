#pragma once
#include<SFML/Graphics.hpp>

class Pen {
private:
	sf::RenderWindow *windowHandle;
	bool hasDrawn, isDown;
	int tileWidth, tileHeight;
	sf::Vector2i gridPosLast;

public:
	sf::Vector2i gridPos;

public:
	Pen(sf::RenderWindow* windowHandle, int tileWidth, int tileHeight);

	bool isDrawing();

	bool update();
};