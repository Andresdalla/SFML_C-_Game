#include "Platform.h"


Platform::Platform(sf::Texture* texture, sf::Vector2f position, sf::Vector2f size)
{
	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(size / 2.0f);
	body.setPosition(position);
}
void Platform::Draw(sf::RenderWindow& window)

{
	window.draw(body);
}
