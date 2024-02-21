#include "Pieces/Queen.h"


std::vector<Move> Queen::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

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
        while (newX >= 0 && newX < squares.size() && newY >= 0 && newY < squares.size()) {
            if (squares[newX][newY] == nullptr) {
                moves.push_back(Move(getX(), getY(), newX, newY, Move::MoveType::Normal));
            }
            else {
                if (squares[newX][newY]->getColor() != getColor()) {
                    moves.push_back(Move(getX(), getY(), newX, newY, Move::MoveType::Capture));
                }
                break;
            }
            newX += dx;
            newY += dy;
        }
    }

    return moves;
}