#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <string>
#include <vector>

enum class PieceType {
	Empty = 0,
	Pawn = 1,
	Rook = 2,
	Knight = 3,
	Bishop = 4,
	Queen = 5,
	King = 6
};

enum class PieceColor {
	White = 0,
	Black = 1
};

const int PAWN = 1;
const int ROOK = 2;
const int KNIGHT = 3;
const int BISHOP = 4;
const int QUEEN = 5;
const int KING = 6;

const int WHITE = 8;
const int BLACK = 16;

const int	EMPTY = 0;
const int	BLACK_PAWN = PAWN | BLACK;
const int	BLACK_ROOK = ROOK | BLACK;
const int	BLACK_KNIGHT = KNIGHT | BLACK;
const int	BLACK_BISHOP = BISHOP | BLACK;
const int	BLACK_QUEEN = QUEEN | BLACK;
const int	BLACK_KING = KING | BLACK;

const int	WHITE_PAWN = PAWN | WHITE;
const int	WHITE_ROOK = ROOK | WHITE;
const int	WHITE_KNIGHT = KNIGHT | WHITE;
const int	WHITE_BISHOP = BISHOP | WHITE;
const int	WHITE_QUEEN = QUEEN | WHITE;
const int	WHITE_KING = KING | WHITE;

class Piece {
public:

	Piece(int type, int x, int y);

	int getType() const;
	int getColor() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states, nlohmann::json config) const;

protected:

	int type_;
	bool isWhite_;
	bool hasMoved_;

	int x_;
	int y_;
};

#endif