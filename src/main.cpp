#include <iostream>
#include <fstream>

#include "Config.h"
#include "Game.h"
#include "SFMLDisplay.h"

#include <nlohmann/json.hpp>

int main()
{
	std::cout << "Reading from config.json" <<std::endl;

	std::ifstream file("config.json");

	if (!file.is_open()) {
		Config::loadDefaultConfig();
	}
	else {
		nlohmann::json json_config = nlohmann::json::parse(file);

		if (!Config::isValidConfig(json_config)) {
			Config::loadDefaultConfig();
		}

		Config::loadConfig(json_config);
	}

	std::cout << "Creating game" << std::endl;

	Game game;
	SFMLDisplay display(game);

	display.run();
}
