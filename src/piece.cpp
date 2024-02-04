#include "Piece.h"
#include <nlohmann/json.hpp>

#include "Config.h"

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

void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	int piece_size = Config::PIECE_SIZE;
	int squareSize = Config::SQUARE_SIZE;

	float centerX = (x_ * squareSize) + squareSize / 2.0f;
	float centerY = (y_ * squareSize) + squareSize / 2.0f;

	sf::Image image;

	std::string assetsPath = Config::ASSETS_PATH;
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

std::vector<std::pair<int, int>> Piece::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {
	// This is a virtual function, so it will be overridden by the derived classes
	return std::vector<std::pair<int, int>>();
}

// Pawn

std::vector<std::pair<int, int>> Pawn::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

	std::vector<std::pair<int, int>> moves;

	// Get the direction of the pawn
	int direction = isWhite_ ? -1 : 1;

	int x = x_;
	int y = y_ + direction;
	int two_squares_y = y_ + 2 * direction;

	// normal moves
	if (y >= 0 && y < squares.size() && squares[x][y] == nullptr) {
		moves.push_back(std::make_pair(x, y));

		if (!hasMoved_ && squares[x][two_squares_y] == nullptr) {
			moves.push_back(std::make_pair(x, two_squares_y));
		}
	}

	// captures
	for (int dx = -1; dx <= 1; dx += 2) {
		int new_x = x_ + dx;
		int new_y = y_ + direction;
		if (new_x >= 0 && new_x < squares.size() && new_y >= 0 && new_y < squares.size()) {
			Piece* piece = squares[new_x][new_y];
			if (piece != nullptr && piece->getColor() != getColor()) {
				moves.push_back(std::make_pair(new_x, new_y));
			}
		}
	}

	return moves;
}