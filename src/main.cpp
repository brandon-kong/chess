#include <iostream>
#include <fstream>

#include "Game.h"
#include "SFMLDisplay.h"

#include <nlohmann/json.hpp>

int main()
{
	std::cout << "Reading from config.json" <<std::endl;

	std::ifstream file("config.json");
	if (!file.is_open()) {
		std::cerr << "Failed to open config.json" << std::endl;
		return 1;
	}

	nlohmann::json config;
	file >> config;

	std::cout << "Creating game" << std::endl;
 
	Game game;
	SFMLDisplay display(game);

	display.run();
}
