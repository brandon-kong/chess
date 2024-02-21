#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <string>
#include <vector>

#include <map>
#include "Move.h"
#include "Config.h"

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

const int	PAWN = 1;
const int	ROOK = 2;
const int	KNIGHT = 3;
const int	BISHOP = 4;
const int	QUEEN = 5;
const int	KING = 6;

const int	WHITE = 8;
const int	BLACK = 16;

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

// Map out the piece images to the piece types

const std::map<int, std::string> pieceImages = {
	{ BLACK_PAWN, "black_pawn" },
	{ BLACK_ROOK, "black_rook" },
	{ BLACK_KNIGHT, "black_knight" },
	{ BLACK_BISHOP, "black_bishop" },
	{ BLACK_QUEEN, "black_queen" },
	{ BLACK_KING, "black_king" },
	{ WHITE_PAWN, "white_pawn" },
	{ WHITE_ROOK, "white_rook" },
	{ WHITE_KNIGHT, "white_knight" },
	{ WHITE_BISHOP, "white_bishop" },
	{ WHITE_QUEEN, "white_queen" },
	{ WHITE_KING, "white_king" }
};

// Class that represents a chess piece
class Piece {
public:

	Piece(int type, int x, int y);

	int getType() const;
	int getColor() const;

	int getX() const;
	int getY() const;

	bool hasMoved() const;

	void move(int x, int y);
	void setSquare(int x, int y);

	virtual std::vector<std::pair<int, int>> getValidMoves(const std::vector<std::vector<Piece*>>& squares) const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:

	int type_;
	bool isWhite_;
	bool hasMoved_;

	int x_;
	int y_;
};

#endif