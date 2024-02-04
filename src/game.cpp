#include "Game.h"
#include "Board.h"
#include "Config.h"

Game::Game() {
	board_ = Board();
}

void Game::start() {
}

void Game::handleMouseClick(sf::Vector2i mousePosition) {
	board_.handleMouseClick(mousePosition);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	board_.draw(target, states);
}