#include "Game.h"
#include "Board.h"

Game::Game() {
}

Game::Game(nlohmann::json config) {
	board_ = Board(config);
}

void Game::start() {
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	board_.draw(target, states);
}