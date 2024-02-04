#ifndef BOARD_H
#define BOARD_H

#include "Config.h"
#include "Piece.h"

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <array>

class Board {
public:
	Board();

	bool isValidMove(int x1, int y1, int x2, int y2);

	// Initializes the board with pieces
	void init();

	void loadFromFEN(std::string fen);

	// Events

	void handleMouseClick(sf::Vector2i mousePosition);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<std::vector<Piece*>> squares_;
	std::vector<Piece> pieces_;

	int board_size_;
	int squareSize_;

	Piece* selectedPiece_ = nullptr;
};

#endif
