#include "Board.h"
#include "Piece.h"
#include "Config.h"
#include "Move.h"

// Piece includes
#include "Pieces/Knight.h"
#include "Pieces/Pawn.h"

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
		else {
			// get selected piece's legal moves
			std::vector<std::pair<int, int>> legalMoves = selectedPiece_->getValidMoves(squares_);
			validMoves_ = legalMoves;
		}
	}
	else {
		// Make sure the move is valid

		if (!isValidMove(selectedPiece_->getX(), selectedPiece_->getY(), x, y)) {
			selectedPiece_ = nullptr;
			return;
		}

		Move move(selectedPiece_->getX(), selectedPiece_->getY(), x, y, Move::MoveType::Normal);
		std::cout << move.toString() << std::endl;

		squares_[selectedPiece_->getX()][selectedPiece_->getY()] = nullptr;
		squares_[x][y] = selectedPiece_;
		selectedPiece_->move(x, y);

		selectedPiece_ = nullptr;
	}
}

bool Board::isValidMove(int x1, int y1, int x2, int y2) {
	// TODO

	// Check if the piece is moving to the same square
	if (x1 == x2 && y1 == y2) {
		return false;
	}

	// Check if the piece is moving to a square that is out of bounds
	if (x2 < 0 || y2 < 0 || x2 >= board_size_ || y2 >= board_size_) {
		return false;
	}

	// Check if the piece is moving to a square that is occupied by a piece of the same color
	if (squares_[x2][y2] != nullptr && squares_[x2][y2]->getColor() == selectedPiece_->getColor()) {
		return false;
	}

	// Check if the piece is moving to a square that is not in the piece's movement pattern
	
	std::vector<std::pair<int, int>> legalMoves = selectedPiece_->getValidMoves(squares_);

	for (int i = 0; i < legalMoves.size(); i++) {
		std::cout << x2 << " " << y2 << std::endl;
		
		if (legalMoves[i].first == x2 && legalMoves[i].second == y2) {
			return true;
		}
	}

	return false;
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
			int type = 0;
			bool isWhite = isupper(fen[i]);

			switch (tolower(fen[i])) {
			case 'p':
				type = PAWN;
				break;
			case 'r':
				type = ROOK;
				break;
			case 'n':
				type = KNIGHT;
				break;
			case 'b':
				type = BISHOP;
				break;
			case 'q':
				type = QUEEN;
				break;
			case 'k':
				type = KING;
				break;
			}

			piece = type;

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

			Piece* p = nullptr;
			switch (type) {
				case PAWN:
					p = new Pawn(piece, x, y);
					break;
				case KNIGHT:
					p = new Knight(piece, x, y);
					break;

				default:
					p = nullptr;
			}

			if (p != nullptr) {
				p->setSquare(x, y);
				pieces_.push_back(*p);
				squares_[x][y] = p;
			}
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

			// Draw the valid moves

			if (selectedPiece_ != nullptr) {
				for (int k = 0; k < validMoves_.size(); k++) {
					if (validMoves_[k].first == i && validMoves_[k].second == j) {
						std::vector<int> validMoveLightSquareColor = Config::SELECTED_LIGHT_SQUARE_COLOR;
						std::vector<int> validMoveDarkSquareColor = Config::SELECTED_DARK_SQUARE_COLOR;

						square.setFillColor((i + j) % 2 == 0 ? sf::Color(validMoveLightSquareColor[0], validMoveLightSquareColor[1], validMoveLightSquareColor[2]) : sf::Color(validMoveDarkSquareColor[0], validMoveDarkSquareColor[1], validMoveDarkSquareColor[2]));
						target.draw(square, states);
					}

				}
			}

			// Draw the pieces
			
			if (squares_[i][j] != nullptr) {
				squares_[i][j]->draw(target, states);
			}
		}
	}

}