#include "Piece.h"
#include <nlohmann/json.hpp>

Piece::Piece(int type, int x, int y) {
	type_ = type;
	isWhite_ = (type & WHITE) == WHITE;
	
	hasMoved_ = false;
	x_ = x;
	y_ = y;
}

int Piece::getType() const {
	return type_;
}

int Piece::getColor() const {
	return isWhite_ ? WHITE : BLACK;
}

int Piece::getX() const {
	return x_;
}

int Piece::getY() const {
	return y_;
}

void Piece::setSquare(int x, int y) {
	x_ = x;
	y_ = y;
}

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states, nlohmann::json config) const {
	int radius = config["piece"]["radius"];
	int squareSize = config["board"]["squareSize"];

	float centerX = (x_ * squareSize) + squareSize / 2.0f;
	float centerY = (y_ * squareSize) + squareSize / 2.0f;

	sf::Image image;

	std::string assetsPath = config["assetsPath"];
	std::string imagePath = assetsPath + pieceImages.at(type_) + ".png";

	image.loadFromFile(imagePath);

	sf::Texture texture;
	texture.loadFromImage(image);
	texture.setSmooth(true);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale((float) squareSize / image.getSize().x, (float) squareSize / image.getSize().y);

	sprite.setOrigin(image.getSize().x / 2.0f, image.getSize().y / 2.0f);
	sprite.setPosition(centerX, centerY);

	target.draw(sprite, states);
}