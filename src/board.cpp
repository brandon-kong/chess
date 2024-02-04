#include "Board.h"
#include "Piece.h"
#include "Config.h"
#include "Move.h"

Board::Board() {

	const int board_size = Config::BOARD_SIZE;
	const int square = Config::SQUARE_SIZE;

	board_size_ = board_size;
	squareSize_ = square;

	squares_ = std::vector<std::vector<Piece*>>(board_size, std::vector<Piece*>(board_size, nullptr));

	init();
}

void Board::init() 
{
	this->loadFromFEN(Config::START_FEN);
}

void Board::handleMouseClick(sf::Vector2i mousePosition) {
	
	int x = mousePosition.x / squareSize_;
	int y = mousePosition.y / squareSize_;

	// Handle out of bounds
	if (x >= board_size_ || y >= board_size_) {
		return;
	}

	if (x < 0 || y < 0) {
		return;
	}

	// If there is no piece selected
	if (selectedPiece_ == nullptr) {
		selectedPiece_ = squares_[x][y];

		if (!selectedPiece_) {
			selectedPiece_ = nullptr;
		}
	}
	else {
		// Move the piece
		Move move(selectedPiece_->getX(), selectedPiece_->getY(), x, y);
		std::cout << move.toString() << std::endl;

		squares_[selectedPiece_->getX()][selectedPiece_->getY()] = nullptr;
		squares_[x][y] = selectedPiece_;
		selectedPiece_->setSquare(x, y);

		selectedPiece_ = nullptr;
	}
}

bool Board::isValidMove(int x, int y) {
	// TODO
	return true;
}

void Board::loadFromFEN(std::string fen) {
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
			if (x >= board_size_ || y >= board_size_) {
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

	// Get the width and height from the config file

	square.setSize(sf::Vector2f(squareSize_, squareSize_));

	// Get the colors from the config file
	std::vector<int> lightSquareColor = Config::LIGHT_SQUARE_COLOR;
	std::vector<int> darkSquareColor = Config::DARK_SQUARE_COLOR;

	for (int i = 0; i < board_size_; i++) {
		for (int j = 0; j < board_size_; j++) {
			square.setPosition(i * squareSize_, j * squareSize_);
			square.setFillColor((i + j) % 2 == 0 ? sf::Color(lightSquareColor[0], lightSquareColor[1], lightSquareColor[2]) : sf::Color(darkSquareColor[0], darkSquareColor[1], darkSquareColor[2]));
			target.draw(square, states);

			// Draw the selected square

			if (selectedPiece_ != nullptr && selectedPiece_->getX() == i && selectedPiece_->getY() == j) {
				std::vector<int> selectedLightSquareColor = Config::SELECTED_LIGHT_SQUARE_COLOR;
				std::vector<int> selectedDarkSquareColor = Config::SELECTED_DARK_SQUARE_COLOR;

				square.setFillColor((i + j) % 2 == 0 ? sf::Color(selectedLightSquareColor[0], selectedLightSquareColor[1], selectedLightSquareColor[2]) : sf::Color(selectedDarkSquareColor[0], selectedDarkSquareColor[1], selectedDarkSquareColor[2]));
				target.draw(square, states);
			}

			// Draw the pieces
			
			if (squares_[i][j] != nullptr) {
				squares_[i][j]->draw(target, states);
			}
		}
	}

}