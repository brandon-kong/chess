#include "Pieces/Knight.h"


std::vector<Move> Knight::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

	std::vector<Move> moves;

    std::vector<std::pair<int, int>> knightMoves = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    int x = getX();
    int y = getY();

    for (const auto& move : knightMoves) {
        int newX = x + move.first;
        int newY = y + move.second;

        if (newX >= 0 && newX < squares.size() && newY >= 0 && newY < squares.size()) {
            Piece* piece = squares[newX][newY];
            if (piece == nullptr) {
                moves.push_back(Move(getX(), getY(), newX, newY, Move::MoveType::Normal));
            }
            else if (piece->getColor() != getColor()) {
				moves.push_back(Move(getX(), getY(), newX, newY, Move::MoveType::Capture));
			}
        }
    }

	return moves;
}