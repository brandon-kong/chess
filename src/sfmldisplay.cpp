#include "SFMLDisplay.h"
#include "InputManager.h"
#include "Config.h"

SFMLDisplay::SFMLDisplay(Game& game) : game_(game) {

	// Get the size of the board
	const int board_size = Config::BOARD_SIZE;
	const int squareSize = Config::SQUARE_SIZE;

	window_.create(sf::VideoMode(board_size * squareSize, board_size * squareSize), "Chess", sf::Style::Close);
}

void SFMLDisplay::run() {

	InputManager inputManager(window_);

	while (window_.isOpen()) {
		sf::Event event;
		
		while (window_.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window_.close();
			}
		}

		if (inputManager.isMouseClick(sf::Mouse::Left)) {
			sf::Vector2i mousePosition = inputManager.getMousePosition();
			game_.getBoard().handleMouseClick(mousePosition);
		}

		draw();
	}
}

void SFMLDisplay::draw() {
	window_.clear();

	game_.draw(window_, sf::RenderStates::Default);

	window_.display();
}