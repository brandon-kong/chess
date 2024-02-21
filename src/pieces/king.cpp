#include "Pieces/King.h"
#include "Move.h"

std::vector<Move> King::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

    std::vector<Move> moves;
    
    std::vector<std::pair<int, int>> directions = {
        {1, 0},  {-1, 0}, {0, 1}, {0, -1},
        {1, 1},  {-1, 1}, {1, -1}, {-1, -1}
    };

    int x = getX();
    int y = getY();
    for (const auto& dir : directions) {
        int dx = dir.first;
        int dy = dir.second;
        int newX = x + dx;
        int newY = y + dy;
        if (newX >= 0 && newX < squares.size() && newY >= 0 && newY < squares.size()) {
            if (squares[newX][newY] == nullptr || squares[newX][newY]->getColor() != getColor()) {
                moves.push_back(Move(getX(), getY(), newX, newY, Move::MoveType::Normal));
            }
        }
    }

    // Castling

    if (!hasMoved()) {
        if (squares[x + 1][y] == nullptr && squares[x + 2][y] == nullptr) {
            if (squares[x + 3][y] != nullptr && squares[x + 3][y]->getPieceType() == ROOK && !squares[x + 3][y]->hasMoved()) {
                moves.push_back(Move(getX(), getY(), x + 2, y, Move::MoveType::Castle));
			}
		}

        if (squares[x - 1][y] == nullptr && squares[x - 2][y] == nullptr && squares[x - 3][y] == nullptr) {
            if (squares[x - 4][y] != nullptr && squares[x - 4][y]->getPieceType() == ROOK && !squares[x - 4][y]->hasMoved()) {
                moves.push_back(Move(getX(), getY(), x - 3, y, Move::MoveType::Castle));
			}
		}
	}

    return moves;
}