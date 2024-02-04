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

enum class PieceDirection {
	Up = 0,
	Down = 1
};

class Piece {
public:

	Piece(int type, bool isWhite, int x, int y);

	int getType() const;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states, nlohmann::json config) const;

protected:

	int type_;
	bool isWhite_;
	bool hasMoved_;

	int x_;
	int y_;
};

#endif