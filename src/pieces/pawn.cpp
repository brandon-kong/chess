#include "Pieces/Pawn.h"


std::vector<Move> Pawn::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

	std::vector<Move> moves;

	// Get the direction of the pawn
	int direction = isWhite_ ? -1 : 1;

	int x = x_;
	int y = y_ + direction;
	int two_squares_y = y_ + 2 * direction;

	// normal moves
	if (y >= 0 && y < squares.size() && squares[x][y] == nullptr) {
		moves.push_back(Move(getX(), getY(), x, y, Move::MoveType::Normal));

		if (!hasMoved_ && squares[x][two_squares_y] == nullptr) {
			moves.push_back(Move(getX(), getY(), x, two_squares_y, Move::MoveType::Normal));
		}
	}

	// captures
	for (int dx = -1; dx <= 1; dx += 2) {
		int new_x = x_ + dx;
		int new_y = y_ + direction;
		if (new_x >= 0 && new_x < squares.size() && new_y >= 0 && new_y < squares.size()) {
			Piece* piece = squares[new_x][new_y];
			if (piece != nullptr && piece->getColor() != getColor()) {
				moves.push_back(Move(getX(), getY(), new_x, new_y, Move::MoveType::Capture));
			}
		}
	}

	return moves;
}