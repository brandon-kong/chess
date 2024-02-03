#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Board.h"
#include "Piece.h"

#include <array>
#include <vector>
#include <iostream>

class Game {
	public:
		Game();
		void start();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	Board board_;
	Player players_[2] = {Player(true), Player(false)};
	Player* currentPlayer_ = &players_[0];
};
	
#endif
