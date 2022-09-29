#include<SFML/Graphics.hpp>
#include<iostream>

#include"Grid.h"

int main() {
	Grid grid(50, 50, 10, 10);
	sf::RenderWindow window(sf::VideoMode(grid.getWidth(), grid.getHeight()), "Window");
	grid.setWindow(window);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
				case sf::Event::MouseButtonPressed:
					grid.set(sf::Mouse::getPosition(window));
			}
			grid.update();
		}

		window.clear();
		grid.render();
		window.display();
	}

	grid.clear();
	return 0;
}