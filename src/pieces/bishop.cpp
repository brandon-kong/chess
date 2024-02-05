#include "Pieces/Bishop.h"

std::vector<std::pair<int, int>> Bishop::getValidMoves(const std::vector<std::vector<Piece*>>& squares) const {

    std::vector<std::pair<int, int>> moves;

    // Define possible directions for diagonal moves
    std::vector<std::pair<int, int>> directions = {
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    // Get the current position of the bishop
    int x = getX();
    int y = getY();

    // Check each direction for possible moves
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