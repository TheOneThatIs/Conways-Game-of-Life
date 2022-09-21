#include<SFML/Graphics.hpp>
#include<iostream>

#include"Grid.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Window");
	Grid grid(10, 5);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				grid.clear();
				window.close();
			}
			grid.update();
		}

		window.clear();
		// Draw here
		window.display();
	}

	return 0;
}