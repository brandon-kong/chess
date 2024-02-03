#pragma once

#ifndef SFMLDISPLAY_H
#define SFMLDISPLAY_H

#include <SFML/Graphics.hpp>

#include "Game.h"

class SFMLDisplay {
	public:
		SFMLDisplay(Game& game);

		void run();
		void draw();

	private:
		Game& game_;
		sf::RenderWindow window_;
};

#endif