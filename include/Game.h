#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include "Player.h"
#include "Board.h"
#include "Piece.h"

#include <array>
#include <vector>
#include <iostream>

class Game {
	public:
		Game();
		Game(nlohmann::json config);
		void start();

		void handleMouseClick(sf::Vector2i mousePosition);

		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	nlohmann::json config_;
	Board board_;
	Player players_[2] = {Player(true), Player(false)};
	Player* currentPlayer_ = &players_[0];
};
	
#endif
