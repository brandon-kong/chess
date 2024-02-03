#pragma once

#include "Player.h"

Player::Player(bool isWhite) : isWhite_(isWhite) {
}

bool Player::isWhite() const {
	return isWhite_;
}