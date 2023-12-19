#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
public:
	//constructores
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);
	

public:
	sf::IntRect uvRect;
private:
	//variables privadas (atributos), siempre ponerlas separadas de las funciones
	//imageCount--> cantidad de fotos q tenemos
	sf::Vector2u imageCount;

	sf::Vector2u currentImage;
	float totalTime;
	//switchTime ----> cuanto va a tomar la animacion
	float switchTime;

};

