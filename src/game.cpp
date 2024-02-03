#include "Game.h"

Game::Game() {
}

void Game::start() {
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	board_.draw(target, states);
}