#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <vector>

enum class PieceType {
	Pawn,
	Rook,
	Knight,
	Bishop,
	Queen,
	King
};

class Piece : public sf::Drawable {
public:

	Piece(PieceType type, bool isWhite);

	PieceType getType() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

	PieceType type_;
	bool isWhite_;
	bool hasMoved_;
};

#endif