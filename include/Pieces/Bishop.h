#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <iostream>
#include <vector>

class Bishop : public Piece
{
public:
	Bishop(int type, int x, int y) : Piece(type, x, y) {}
	std::vector<std::pair<int, int>> getValidMoves(const std::vector<std::vector<Piece*>>& board) const override;
};

#endif