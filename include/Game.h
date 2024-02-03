#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <SFML/Graphics.hpp>

#include <array>
#include <vector>
#include <iostream>

class Game:
	public sf::Drawable {
		private:
			Board board;
			std::array<Piece, 16> whitePieces;
			std::array<Piece, 16> blackPieces;
			Piece* selectedPiece;
			std::vector<sf::RectangleShape> possibleMoveSquares;
			std::string lastMove;
	}

#endif
