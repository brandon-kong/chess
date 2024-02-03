#pragma once

#ifndef PLAYER_H
#define PLAYER_H

class Player {
	public:
		Player(bool isWhite);
		bool isWhite() const;
	private:
		bool isWhite_;
};

#endif