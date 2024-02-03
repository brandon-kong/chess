#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

class Piece : public sf::Drawable {
	public:
		Piece(char type='P', bool player=true, int pos=-1, bool moved=false) : m_type{type}, m_player{player}, m_position{-1}, m_moved{true}, enPassant{-1} {}

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			target.draw(m_sprite);
		}
}
