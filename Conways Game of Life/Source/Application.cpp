#include<SFML/Graphics.hpp>
#include<iostream>

#include"Grid.h"

int main() {
	sf::RenderWindow window;
	Grid grid(&window, 10, 10, 50, 50);
	window.create(sf::VideoMode(grid.getWidth(), grid.getHeight()), "Window");
	grid.setWindow(window);
	sf::Clock clock;
	sf::Time elapsed = clock.getElapsedTime();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
				case sf::Event::MouseMoved:
					grid.set(sf::Mouse::getPosition(window));
				case sf::Event::MouseButtonPressed:
					grid.set(sf::Mouse::getPosition(window));
				case sf::Event::KeyPressed:
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
						grid.runSimulation();
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
						grid.stepsToSimulate = 1;
					}
						
			}
		}

		window.clear();
		grid.render();

		if (elapsed.asSeconds() >= 0.25) {
			grid.update();
			elapsed = clock.restart();
		}
		window.display();

		elapsed = clock.getElapsedTime();
	}

	grid.clear();
	return 0;
}