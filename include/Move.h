#ifndef MOVE_H
#define MOVE_H

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

	Move(int fromX, int fromY, int toX, int toY, MoveType type) : fromX_(fromX), fromY_(fromY), toX_(toX), toY_(toY), type_(type) {}

	int getFromX() const { return fromX_; }
	int getFromY() const { return fromY_; }
	int getToX() const { return toX_; }
	int getToY() const { return toY_; }

	std::string toString() const {
		std::string from = std::to_string(fromX_) + std::to_string(fromY_);
		std::string to = std::to_string(toX_) + std::to_string(toY_);
		return from + ", " + to;
	}

private:
	int fromX_;
	int fromY_;
	int toX_;
	int toY_;
	MoveType type_;
};

#endif