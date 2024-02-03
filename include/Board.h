#ifndef BOARD_H
#define BOARD_H

#include <SFML/Grpahics.hpp>
#include <iostream>
#include <array>

class Board : public sf::Drawable {
	public:
		Board();

	private:
		std::array<sf::RectangleShape, 64> boardSquares;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
}

#endif
