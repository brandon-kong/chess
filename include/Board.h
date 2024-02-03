#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

class Board {
public:
	Board();

	const Piece* getPiece(int x, int y) const;
	bool movePiece(int x1, int y1, int x2, int y2);

	// Initializes the board with pieces
	void init();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::array<std::array<Piece*, 8>, 8> squares_;
	std::vector<Piece> pieces_;
};

#endif
