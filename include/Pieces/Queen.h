#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include "Move.h"

#include <iostream>
#include <vector>

class Queen : public Piece
{
public:
	Queen(int type, int x, int y) : Piece(type, x, y) {}
	std::vector<Move> getValidMoves(const std::vector<std::vector<Piece*>>& board) const override;
};

#endif