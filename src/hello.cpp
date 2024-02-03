#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	auto window = sf::RenderWindow{ {1920u, 1080u}, "Cmake SFML Project"};
	window.setFramerateLimit(144);

	while (window.isOpen()) {
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.display();
	}

	return 0;
}
