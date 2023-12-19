#include "Animation.h"


Animation::Animation(sf::Texture* texure, sf::Vector2u imageCount, float switchTime)
{
	this -> imageCount = imageCount;
	this -> switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	uvRect.width = texure->getSize().x / float(imageCount.x);
	uvRect.height= texure->getSize().y / float(imageCount.y);



}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;
	if(totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}
	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;

}
