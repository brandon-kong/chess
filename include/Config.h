#ifndef CONFIG_H
#define CONFIG_H

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

class Config {

public:
	Config();

	static bool isValidConfig(nlohmann::json config);
	
	static void loadDefaultConfig();
	static void loadConfig(nlohmann::json config);

	static std::string ASSETS_PATH;

	// Sizes

	static int BOARD_SIZE;
	static int SQUARE_SIZE;
	static int PIECE_SIZE;
	
	static std::string START_FEN;

	// Colors

	static std::vector<int> LIGHT_SQUARE_COLOR;
	static std::vector<int> DARK_SQUARE_COLOR;

	static std::vector<int> SELECTED_LIGHT_SQUARE_COLOR;
	static std::vector<int> SELECTED_DARK_SQUARE_COLOR;


};

#endif