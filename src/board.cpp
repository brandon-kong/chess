#include "Board.h"
#include "Piece.h"

Board::Board() {
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

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			square.setPosition(i * 100, j * 100);
			square.setFillColor((i + j) % 2 == 0 ? sf::Color(255, 206, 158) : sf::Color(209, 139, 71));
			target.draw(square, states);
		}
	}
}