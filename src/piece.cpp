#include "Piece.h"
#include <nlohmann/json.hpp>

#include "Config.h"
#include "Pieces/Pawn.h"

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

int Piece::getPieceType() const {
	return type_ & 7;
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

bool Piece::hasMoved() const {
	return hasMoved_;
}

void Piece::setSquare(int x, int y) {
	x_ = x;
	y_ = y;
}

void Piece::move(int x, int y) {
	setSquare(x, y);

	hasMoved_ = true;
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

std::vector<Move> Piece::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {
	// This is a virtual function, so it will be overridden by the derived classes
	return std::vector<Move>();
}

char Piece::getSymbol() const {
	
	char symbol = 'p';

	switch (getPieceType()) {
		case PAWN:
			symbol = 'P';
		case KNIGHT:
			symbol = 'N';
		case BISHOP:
			symbol = 'B';
		case ROOK:
			symbol = 'R';
		case QUEEN:
			symbol = 'Q';
		case KING:
			symbol = 'K';
		default:
			symbol = 'p';
	}

	return isWhite_ ? symbol : tolower(symbol);
}
