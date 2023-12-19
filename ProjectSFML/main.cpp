#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "White Yanfri",sf::Style::Close | sf::Style::Resize);
	sf::Texture textura;
	textura.loadFromFile("pepeTetaCompleto.png");

	Player player(&textura, sf::Vector2u(4, 4), 0.2f,100.0f);
	float deltaTime;
	sf::Clock clock;
	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				printf("Altura ventana: %i Ancho ventana %i\n", evt.size.height, evt.size.width);
				break;
			case sf::Event::TextEntered:
				if (evt.text.unicode < 128) {
					printf("%c", evt.text.unicode);
				}
			}
		}
		
		player.Update(deltaTime);

		window.clear();
		player.Draw(window);
		window.display();
	}

    return 0;
	
}