#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <iostream>
#include <vector>

class Pawn : public Piece
{
public:
	Pawn(int type, int x, int y) : Piece(type, x, y) {}
	std::vector<std::pair<int, int>> getValidMoves(const std::vector<std::vector<Piece*>>& board) const override;
};

#endif