#ifndef KING_H
#define KING_H

#include "Piece.h"
#include <iostream>
#include <vector>

class King : public Piece
{
public:
	King(int type, int x, int y) : Piece(type, x, y) {}
	std::vector<std::pair<int, int>> getValidMoves(const std::vector<std::vector<Piece*>>& board) const override;
};

#endif