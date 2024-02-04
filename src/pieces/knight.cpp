#include "Pieces/Knight.h"


std::vector<std::pair<int, int>> Knight::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

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