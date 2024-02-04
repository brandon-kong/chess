#include "SFMLDisplay.h"


SFMLDisplay::SFMLDisplay(Game& game, nlohmann::json config) : game_(game), config_(config) {

	// Handle errors for board
	
	if (!config["board"].is_object()) {
		std::cerr << "Error: board is not an object" << std::endl;
		exit(1);
	}

	if (!config["board"]["width"].is_number_integer()) {
		std::cerr << "Error: width is not an integer" << std::endl;
		exit(1);
	}

	if (!config["board"]["height"].is_number_integer()) {
		std::cerr << "Error: height is not an integer" << std::endl;
		exit(1);
	}

	if (!config["board"]["squareSize"].is_number_integer()) {
		std::cerr << "Error: squareSize is not an integer" << std::endl;
		exit(1);
	}

	// Get the size of the board
	const int width = config["board"]["width"];
	const int height = config["board"]["height"];
	const int squareSize = config["board"]["squareSize"];


	window_.create(sf::VideoMode(width * squareSize, height * squareSize), "Chess", sf::Style::Close);
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