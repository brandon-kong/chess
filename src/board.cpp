#include "Board.h"
#include "Piece.h"

Board::Board() {
}

Board::Board(nlohmann::json config) {
	config_ = config;

	const int width = config_["board"]["width"];
	const int height = config_["board"]["height"];
	const int square = config_["board"]["squareSize"];

	width_ = width;
	height_ = height;
	squareSize_ = square;

	squares_ = std::vector<std::vector<Piece*>>(width, std::vector<Piece*>(height, nullptr));

	init();
}

void Board::init() {

	if (!config_["board"]["startFEN"].is_string()) {
		std::cerr << "Error: startFEN is not a string" << std::endl;
		exit(1);
	}

	this->loadFromFEN(config_["board"]["startFEN"]);
}

void Board::handleMouseClick(sf::Vector2i mousePosition) {
	// Get the position of the mouse
	
	int x = mousePosition.x / squareSize_;
	int y = mousePosition.y / squareSize_;

	// Handle out of bounds
	if (x >= width_ || y >= height_) {
		return;
	}

	// If there is no piece selected
	if (selectedPiece_ == nullptr) {
		selectedPiece_ = squares_[x][y];

		if (selectedPiece_ == EMPTY) {
			selectedPiece_ = nullptr;
		}
	}
	else {
		// Move the piece
		squares_[selectedPiece_->getX()][selectedPiece_->getY()] = EMPTY;
		squares_[x][y] = selectedPiece_;
		selectedPiece_->setSquare(x, y);

		//selectedPiece_->setPosition(x * squareSize_, y * squareSize_);

		selectedPiece_ = nullptr;
	}
}

bool Board::isValidMove(int x, int y) {
	// return true for now
	return true;
}

void Board::loadFromFEN(std::string fen) {
	// It should work for strings greater than 8

	int x = 0;
	int y = 0;

	for (int i = 0; i < fen.size(); i++) {
		if (fen[i] == '/') {
			x = 0;
			y++;
		}
		else if (isdigit(fen[i])) {
			x += fen[i] - '0';
		}
		else {
			int piece = 0;
			bool isWhite = isupper(fen[i]);

			switch (tolower(fen[i])) {
			case 'p':
				piece = PAWN;
				break;
			case 'r':
				piece = ROOK;
				break;
			case 'n':
				piece = KNIGHT;
				break;
			case 'b':
				piece = BISHOP;
				break;
			case 'q':
				piece = QUEEN;
				break;
			case 'k':
				piece = KING;
				break;
			}

			if (!isWhite) {
				piece |= BLACK;
			}
			else {
				piece |= WHITE;
			}

			// handle out of bounds

			if (x >= width_ || y >= height_) {
				std::cerr << "Error: x or y is out of bounds" << std::endl;
				exit(1);
			}

			Piece* p = new Piece(piece, x, y);
			pieces_.push_back(*p);
			squares_[x][y] = p;

			x++;
		}
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
				squares_[i][j]->draw(target, states, config_);
			}
		}
	}

}