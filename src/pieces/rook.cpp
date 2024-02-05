#include "Pieces/Rook.h"


std::vector<std::pair<int, int>> Rook::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

    std::vector<std::pair<int, int>> moves;

    std::vector<std::pair<int, int>> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int x = getX();
    int y = getY();
    for (const auto& dir : directions) {
        int dx = dir.first;
        int dy = dir.second;
        for (int i = 1; i < squares.size(); ++i) {
            int newX = x + i * dx;
            int newY = y + i * dy;
            if (newX >= 0 && newX < squares.size() && newY >= 0 && newY < squares.size()) {
                if (squares[newX][newY] == nullptr) {
                    moves.push_back({ newX, newY });
                }
                else if (squares[newX][newY]->getColor() != getColor()) {
                    moves.push_back({ newX, newY });
                    break;
                }
                else {
                    break;
                }
            }
            else {
                break;
            }
        }
    }

    return moves;
}