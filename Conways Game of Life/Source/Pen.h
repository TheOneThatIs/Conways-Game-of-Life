#pragma once
#include<SFML/Graphics.hpp>

class Pen {
private:
	sf::RenderWindow &windowHandle;
	sf::Vector2f gridPos;

public:
	Pen(sf::RenderWindow* windowHandle);

	void update();
};