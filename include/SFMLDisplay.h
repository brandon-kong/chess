#pragma once

#ifndef SFMLDISPLAY_H
#define SFMLDISPLAY_H

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>

#include "Game.h"

class SFMLDisplay {
	public:
		SFMLDisplay(Game& game, nlohmann::json config);

		void run();
		void draw();

	private:
		Game& game_;
		sf::RenderWindow window_;
		nlohmann::json config_;
};

#endif