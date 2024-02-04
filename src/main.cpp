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

	std::cout << "Parsing config.json" << std::endl;

	nlohmann::json config = nlohmann::json::parse(file);

	std::cout << "Successfully parsed config.json" << std::endl;
	std::cout << "Creating game" << std::endl;
 
	Game game(config);
	SFMLDisplay display(game, config);

	display.run();
}
