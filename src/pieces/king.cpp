#include "Pieces/King.h"


std::vector<std::pair<int, int>> King::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

    std::vector<std::pair<int, int>> moves;
    
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
                moves.push_back({ newX, newY });
            }
        }
    }

    return moves;
}