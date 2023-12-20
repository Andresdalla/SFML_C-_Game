#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount,switchTime)
{
	this->speed = speed;
	row = 0;
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);
	body.setOrigin(body.getSize() / 2.0f);


} 

Player::~Player()
{

}
void Player::Update(float deltaTime)
{
		sf::Vector2f movement(0.0f, 0.0f);
		bool movio = false;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			movement.x -= speed * deltaTime;
			movio = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			movement.x += speed * deltaTime;
			movio = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			movement.y -= speed * deltaTime;
			movio = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			movement.y += speed * deltaTime;
			movio = true;
		}

		if (movement.y < 0.0f)
		{
			row = 1;
		}
		else if (movement.y > 0.0f)
		{
			row = 0;
		}
		else if (movement.x > 0.0f)
		{
			row = 3;
		}
		else if (movement.x < 0.0f)
		{
			row = 2;
		}
		if (movio)
		{
			animation.Update(row, deltaTime);
			body.setTextureRect(animation.uvRect);
			body.move(movement);

		}
		else
		{
			animation.Update(row, 0);
			body.setTextureRect(animation.uvRect);
			body.move(movement);
		}
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
