#include<SFML/Graphics.hpp>
#include<iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Window");

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		// Draw here
		window.display();
	}

	return 0;
}