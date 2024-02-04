#include "Piece.h"
#include <nlohmann/json.hpp>

Piece::Piece(int type, bool isWhite, int x, int y) {
	type_ = type;
	isWhite_ = isWhite;
	hasMoved_ = false;
	x_ = x;
	y_ = y;
}

int Piece::getType() const {
	return type_;
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states, nlohmann::json config) const {
	int radius = config["piece"]["radius"];
	int squareSize = config["board"]["squareSize"];

	float centerX = x_ + squareSize / 2.0f;
	float centerY = y_ + squareSize / 2.0f;

	sf::CircleShape shape(radius);
	shape.setOrigin(radius, radius);

	shape.setFillColor(isWhite_ ? sf::Color::White : sf::Color::Black);
	shape.setPosition(centerX, centerY);
	target.draw(shape, states);
}