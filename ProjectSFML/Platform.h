#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
class Platform
{
public:
	Platform(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size);

	void Draw(sf::RenderWindow& window);
	Collider GetCollider() { return Collider(body); }
private:
	sf::RectangleShape body;
};

