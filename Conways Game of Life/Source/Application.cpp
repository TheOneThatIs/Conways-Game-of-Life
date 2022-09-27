#include<SFML/Graphics.hpp>
#include<iostream>

#include"Grid.h"

int main() {
	Grid grid(10, 7);
	sf::RenderWindow window(sf::VideoMode(grid.getWidth(), grid.getHeight()), "Window");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			grid.update();
		}

		window.clear();
		grid.render(&window);
		window.display();
	}

	grid.clear();
	return 0;
}