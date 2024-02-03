#include <iostream>
#include <fstream>

#include "Game.h"
#include "SFMLDisplay.h"

int main()
{
	std::cout << "Reading from config.json" <<std::endl;

	std::ifstream file("config.json");
	if (!file.is_open()) {
		std::cerr << "Failed to open config.json" << std::endl;
		return 1;
	}
 
	Game game;
	SFMLDisplay display(game);

	display.run();
}
