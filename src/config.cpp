#include "Config.h"

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <fstream>

int Config::BOARD_SIZE;
int Config::SQUARE_SIZE;
int Config::PIECE_SIZE;
std::vector<int> Config::LIGHT_SQUARE_COLOR;
std::vector<int> Config::DARK_SQUARE_COLOR;
std::vector<int> Config::SELECTED_LIGHT_SQUARE_COLOR;
std::vector<int> Config::SELECTED_DARK_SQUARE_COLOR;
std::string Config::ASSETS_PATH;
std::string Config::START_FEN;

Config::Config() {
	// Load default settings
	loadDefaultConfig();
}

void Config::loadDefaultConfig()
{
	// Assets path
	Config::ASSETS_PATH = "assets/";

	// Board size
	Config::BOARD_SIZE = 8; // 8x8 board
	Config::SQUARE_SIZE = 100; // Each square is 100x100 pixels
	Config::PIECE_SIZE = 80; // Each piece is 80x80 pixels

	// Colors
	Config::LIGHT_SQUARE_COLOR = std::vector<int>(3);
	Config::LIGHT_SQUARE_COLOR[0] = 232;
	Config::LIGHT_SQUARE_COLOR[1] = 237;
	Config::LIGHT_SQUARE_COLOR[2] = 249;
	
	Config::DARK_SQUARE_COLOR = std::vector<int>(3);
	Config::DARK_SQUARE_COLOR[0] = 183;
	Config::DARK_SQUARE_COLOR[1] = 192;
	Config::DARK_SQUARE_COLOR[2] = 216;

	Config::SELECTED_LIGHT_SQUARE_COLOR = std::vector<int>(3);
	Config::SELECTED_LIGHT_SQUARE_COLOR[0] = 95;
	Config::SELECTED_LIGHT_SQUARE_COLOR[1] = 182;
	Config::SELECTED_LIGHT_SQUARE_COLOR[2] = 194;

	Config::SELECTED_DARK_SQUARE_COLOR = std::vector<int>(3);
	Config::SELECTED_DARK_SQUARE_COLOR[0] = 0;
	Config::SELECTED_DARK_SQUARE_COLOR[1] = 123;
	Config::SELECTED_DARK_SQUARE_COLOR[2] = 135;

	// Start FEN
	Config::START_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"; // Standard starting position
}

void Config::loadConfig(nlohmann::json config) {

	if (!isValidConfig(config)) {
		std::cerr << "Error: Invalid config, using default settings" << std::endl;
		loadDefaultConfig();
		return;
	}

	// Load settings from JSON
	Config::ASSETS_PATH = config["assets_path"];

	Config::BOARD_SIZE = config["board_size"];
	Config::SQUARE_SIZE = config["square_size"];
	Config::PIECE_SIZE = config["piece_size"];

	Config::LIGHT_SQUARE_COLOR = std::vector<int>(3);
	Config::LIGHT_SQUARE_COLOR[0] = config["light_square_color"][0];
	Config::LIGHT_SQUARE_COLOR[1] = config["light_square_color"][1];
	Config::LIGHT_SQUARE_COLOR[2] = config["light_square_color"][2];

	Config::DARK_SQUARE_COLOR = std::vector<int>(3);
	Config::DARK_SQUARE_COLOR[0] = config["dark_square_color"][0];
	Config::DARK_SQUARE_COLOR[1] = config["dark_square_color"][1];
	Config::DARK_SQUARE_COLOR[2] = config["dark_square_color"][2];

	Config::SELECTED_LIGHT_SQUARE_COLOR = std::vector<int>(3);
	Config::SELECTED_LIGHT_SQUARE_COLOR[0] = config["selected_light_square_color"][0];
	Config::SELECTED_LIGHT_SQUARE_COLOR[1] = config["selected_light_square_color"][1];
	Config::SELECTED_LIGHT_SQUARE_COLOR[2] = config["selected_light_square_color"][2];

	Config::SELECTED_DARK_SQUARE_COLOR = std::vector<int>(3);
	Config::SELECTED_DARK_SQUARE_COLOR[0] = config["selected_dark_square_color"][0];
	Config::SELECTED_DARK_SQUARE_COLOR[1] = config["selected_dark_square_color"][1];
	Config::SELECTED_DARK_SQUARE_COLOR[2] = config["selected_dark_square_color"][2];

	Config::START_FEN = config["start_fen"];
}

bool Config::isValidConfig(nlohmann::json config) {
	std::ifstream file("config.json");

	if (!file.is_open()) {
		return false;
	}

	if (!config["assets_path"].is_string()) {
		std::cerr << "Error: assets_path is not a string" << std::endl;
		return false;
	}

	if (!config["board_size"].is_number_integer()) {
		std::cerr << "Error: board_size is not an integer" << std::endl;
		return false;
	}

	if (!config["square_size"].is_number_integer()) {
		std::cerr << "Error: square_size is not an integer" << std::endl;
		return false;
	}

	if (!config["piece_size"].is_number_integer()) {
		std::cerr << "Error: piece_size is not an integer" << std::endl;
		return false;
	}

	if (!config["light_square_color"].is_array() || config["light_square_color"].size() != 3) {
		std::cerr << "Error: light_square_color is not an array of size 3" << std::endl;
		return false;
	}

	if (!config["dark_square_color"].is_array() || config["dark_square_color"].size() != 3) {
		std::cerr << "Error: dark_square_color is not an array of size 3" << std::endl;
		return false;
	}

	if (!config["selected_light_square_color"].is_array() || config["selected_light_square_color"].size() != 3) {
		std::cerr << "Error: selected_light_square_color is not an array of size 3" << std::endl;
		return false;
	}

	if (!config["selected_dark_square_color"].is_array() || config["selected_light_square_color"].size() != 3) {
		std::cerr << "Error: selected_dark_square_color is not an array of size 3" << std::endl;
		return false;
	}

	if (!config["start_fen"].is_string()) {
		std::cerr << "Error: start_fen is not a string" << std::endl;
		return false;
	}

	return true;
}