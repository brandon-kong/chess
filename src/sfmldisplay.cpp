#include "SFMLDisplay.h"

SFMLDisplay::SFMLDisplay(Game& game) : game_(game) {
	window_.create(sf::VideoMode(800, 800), "Chess", sf::Style::Close);
}

void SFMLDisplay::run() {
	while (window_.isOpen()) {
		sf::Event event;
		
		while (window_.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window_.close();
			}
		}

		draw();
	}
}

void SFMLDisplay::draw() {
	window_.clear();

	game_.draw(window_, sf::RenderStates::Default);

	window_.display();
}