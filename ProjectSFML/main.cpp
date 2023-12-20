#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "White Yanfri",sf::Style::Close);
	sf::Texture textura;
	textura.loadFromFile("pepeTetaCompleto.png");
	sf::Texture textPelota;
	textPelota.loadFromFile("caja.png");
	Player player(&textura, sf::Vector2u(4, 4), 0.2f,100.0f);
	Platform bola(&textPelota, sf::Vector2f(10.0f, 10.0f), sf::Vector2f(100.0f, 100.0f));

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
			case sf::Event::TextEntered:
				if (evt.text.unicode < 128) {
					printf("%c", evt.text.unicode);
				}
			}
		}
		
		player.Update(deltaTime);
		Collider a = player.GetCollider();
		bola.GetCollider().CheckCollision(a,0.0f);
		window.clear();
		player.Draw(window);
		bola.Draw(window);
		window.display();
	}

    return 0;
	
}