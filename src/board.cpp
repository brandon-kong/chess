#include "Board.h"
#include "Piece.h"

Board::Board() {
}

Board::Board(nlohmann::json config) {
	config_ = config;

	const int width = config_["board"]["width"];
	const int height = config_["board"]["height"];

	width_ = width;
	height_ = height;

	std::cout << "Width: " << width << std::endl;

	squares_ = std::vector<std::vector<Piece*>>(width, std::vector<Piece*>(height, nullptr));

	init();
}

void Board::init() {
	
	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			squares_[i][j] = nullptr;
		}
	}

	std::cout << squares_.size() << std::endl;

	// Initialize the pieces
	for (int i = 0; i < width_; i++) {
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

	if (config_["colors"]["lightSquare"].size() != 3) {
		std::cerr << "Error: lightSquare does not have 3 elements" << std::endl;
		exit(1);
	}

	if (config_["colors"]["darkSquare"].size() != 3) {
		std::cerr << "Error: darkSquare does not have 3 elements" << std::endl;
		exit(1);
	}

	if (!config_["colors"]["lightSquare"][0].is_number_integer() || !config_["colors"]["lightSquare"][1].is_number_integer() || !config_["colors"]["lightSquare"][2].is_number_integer()) {
		std::cerr << "Error: lightSquare does not have 3 integers" << std::endl;
		exit(1);
	}

	if (!config_["colors"]["darkSquare"][0].is_number_integer() || !config_["colors"]["darkSquare"][1].is_number_integer() || !config_["colors"]["darkSquare"][2].is_number_integer()) {
		std::cerr << "Error: darkSquare does not have 3 integers" << std::endl;
		exit(1);
	}

	// Get the width and height from the config file

	int squareSize = config_["board"]["squareSize"];

	square.setSize(sf::Vector2f(squareSize, squareSize));

	// Get the colors from the config file
	std::vector<int> lightSquareColor = config_["colors"]["lightSquare"];
	std::vector<int> darkSquareColor = config_["colors"]["darkSquare"];

	for (int i = 0; i < width_; i++) {
		for (int j = 0; j < height_; j++) {
			square.setPosition(i * squareSize, j * squareSize);
			square.setFillColor((i + j) % 2 == 0 ? sf::Color(lightSquareColor[0], lightSquareColor[1], lightSquareColor[2]) : sf::Color(darkSquareColor[0], darkSquareColor[1], darkSquareColor[2]));
			target.draw(square, states);

			// Draw the pieces

			if (squares_[i][j] != nullptr) {
				squares_[i][j]->draw(target, states);
			}
		}
	}

}