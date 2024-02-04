#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <iostream>
#include <vector>

class Knight : public Piece
{
public:
	Knight(int type, int x, int y) : Piece(type, x, y) {}
	std::vector<std::pair<int, int>> getValidMoves(const std::vector<std::vector<Piece*>>& board) const override;
};

#endif