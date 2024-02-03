#include "Piece.h"

Piece::Piece(PieceType type, bool isWhite) {
	type_ = type;
	isWhite_ = isWhite;
	hasMoved_ = false;
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::CircleShape shape(50);
	shape.setFillColor(isWhite_ ? sf::Color::White : sf::Color::Black);
	shape.setPosition(100, 100);
	target.draw(shape, states);
}