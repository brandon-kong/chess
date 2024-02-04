#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"
#include <iostream>
#include <vector>

class Pawn : public Piece
{
public:
	Pawn(int type, int x, int y);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<std::pair<int, int>> getValidMoves(const std::vector<std::vector<Piece*>>& board) const;

private:
	int type;
	int x;
	int y;
};

#endif