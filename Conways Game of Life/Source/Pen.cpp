#include "Pen.h"
#include<iostream>

Pen::Pen(sf::RenderWindow *windowHandle) : windowHandle(*windowHandle) {

}

void Pen::update() {
	std::cout << "Mouse pos: [" << sf::Mouse::getPosition(windowHandle).x << "], [" << sf::Mouse::getPosition(windowHandle).y << "]" << std::endl;
}