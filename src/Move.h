#ifndef MOVE_H
#define MOVE_H

#include <string>

class Move {
public:
	enum class MoveType {
		Normal,
		Capture,
		Castle,
		EnPassant,
		Promotion
	};

	Move(int fromX, int fromY, int toX, int toY, MoveType type = MoveType::Normal) :
		fromX_(fromX), fromY_(fromY), toX_(toX), toY_(toY), type_(type) {}

	int getFromX() const { return fromX_; }
	int getFromY() const { return fromY_; }
	int getToX() const { return toX_; }
	int getToY() const { return toY_; }

	std::string toString() const {
		std::string move = "";
		move += (char)(fromX_ + 'a');
		move += (char)('8' - fromY_);
		move += (char)(toX_ + 'a');
		move += (char)('8' - toY_);
		return move;
	}

	MoveType getType() const { return type_; }

private:
	int fromX_;
	int fromY_;
	int toX_;
	int toY_;
	MoveType type_;
};

#endif