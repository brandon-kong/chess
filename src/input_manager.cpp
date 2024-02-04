#include "InputManager.h"
#include <SFML/Graphics.hpp>


InputManager::InputManager(sf::RenderWindow& target) : target(target) {
}

sf::Vector2i InputManager::getMousePosition() {
	return sf::Mouse::getPosition(target);
}

bool InputManager::isMouseClick(sf::Mouse::Button button) {
	if (sf::Mouse::isButtonPressed(button)) {
		if (mouseButtons[button] == false) {
			mouseButtons[button] = true;
			return true;
		}
	}
	else {
		mouseButtons[button] = false;
	}
	return false;
}

bool InputManager::isKeyDown(sf::Keyboard::Key key) {
	if (sf::Keyboard::isKeyPressed(key)) {
		if (keys[key] == false) {
			keys[key] = true;
			return true;
		}
	}
	else {
		keys[key] = false;
	}
	return false;
}