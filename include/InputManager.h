#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <map>

class InputManager
{
public:
	InputManager(sf::RenderWindow& target);
	~InputManager() {}

	bool isMouseClick(sf::Mouse::Button button);
	bool isKeyDown(sf::Keyboard::Key key);

	sf::Vector2i getMousePosition();

private:
	std::map<sf::Mouse::Button, bool> mouseButtons;
	std::map<sf::Keyboard::Key, bool> keys;
	sf::RenderWindow& target;
};

#endif