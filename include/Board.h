#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include <iostream>
#include <array>

class Board {
public:
	Board();
	Board(nlohmann::json config);

	bool isValidMove(int x, int y);

	// Initializes the board with pieces
	void init();

	void loadFromFEN(std::string fen);

	// Events

	void handleMouseClick(sf::Vector2i mousePosition);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	nlohmann::json config_;
	std::vector<std::vector<Piece*>> squares_;
	std::vector<Piece> pieces_;

	int width_;
	int height_;
	int squareSize_;

	Piece* selectedPiece_ = nullptr;
};

#endif
