#include "Board.h"
#include "Piece.h"

Board::Board() {
}

Board::Board(nlohmann::json config) {
	config_ = config;
	init();
}

void Board::init() {
	
	// Initialize the board with pieces
	for (int i = 0; i < 8; i++) {
		squares_[i][1] = new Piece(PieceType::Pawn, false);
		squares_[i][6] = new Piece(PieceType::Pawn, true);
	}
}

void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	
	// Draw the board
	sf::RectangleShape square(sf::Vector2f(100, 100));

	// Handle errors for colors
	if (!config_["colors"].is_object()) {
		std::cerr << "Error: colors is not an object" << std::endl;
		exit(1);
	}

	if (!config_["colors"]["lightSquare"].is_array()) {
		std::cerr << "Error: lightSquare is not an array" << std::endl;
		exit(1);
	}

	if (!config_["colors"]["darkSquare"].is_array()) {
		std::cerr << "Error: darkSquare is not an array" << std::endl;
		exit(1);
	}

	// Get the colors from the config file
	std::vector<int> lightSquareColor = config_["colors"]["lightSquare"];
	std::vector<int> darkSquareColor = config_["colors"]["darkSquare"];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			square.setPosition(i * 100, j * 100);
			square.setFillColor((i + j) % 2 == 0 ? sf::Color(lightSquareColor[0], lightSquareColor[1], lightSquareColor[2]) : sf::Color(darkSquareColor[0], darkSquareColor[1], darkSquareColor[2]));
			target.draw(square, states);
		}
	}
}