#ifndef MOVE_H
#define MOVE_H

#include "Piece.h"
#include <iostream>

#include <string>

class Move {
public:

	enum class MoveType {
		Normal,
		Capture,
		EnPassant,
		Castle,
		Promotion
	};

	Move() : fromX_(-1), fromY_(-1), toX_(-1), toY_(-1), type_(MoveType::Normal) {}
	Move(int fromX, int fromY, int toX, int toY, MoveType type) : fromX_(fromX), fromY_(fromY), toX_(toX), toY_(toY), type_(type) {}

	int getFromX() const { return fromX_; }
	int getFromY() const { return fromY_; }
	int getToX() const { return toX_; }
	int getToY() const { return toY_; }

	MoveType getType() const { return type_; }

	std::string toString() const {
		// algebraic notation

		std::string result = "";

		if (type_ == MoveType::Castle) {
			if (toX_ == 6) {
				result = "O-O";
			}
			else {
				result = "O-O-O";
			}
			return result;
		}

		result += (char)('a' + fromX_);
		result += (char)('8' - fromY_);

		if (type_ == MoveType::Capture) {
			result += "x";
		}

		result += (char)('a' + toX_);
		result += (char)('8' - toY_);

		return result;
	}

private:
	int fromX_;
	int fromY_;
	int toX_;
	int toY_;
	MoveType type_;

};

#endif