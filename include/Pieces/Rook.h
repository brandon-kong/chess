#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "Move.h"

#include <iostream>
#include <vector>

class Rook : public Piece
{
public:
	Rook(int type, int x, int y) : Piece(type, x, y) {}
	std::vector<Move> getValidMoves(const std::vector<std::vector<Piece*>>& board) const override;
};

#endif