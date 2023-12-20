#include "Collider.h"

Collider::Collider(sf::RectangleShape& body) :
    body(body)
{

}

bool Collider::CheckCollision(Collider & other, float push)
{
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float interX = abs(deltaX) - (otherHalfSize.x - thisHalfSize.x);
    float interY = abs(deltaY) - (otherHalfSize.y - thisHalfSize.y);
    
    if ((interX > 0.0f) && (interY > 0.0f)) 
    {
        push = std::min(std::max(push, 0.0f), 1.0f);
        if (interX > interY) 
        {
            if (deltaX > 0.0f) {
                Move(interX * (1.0f - push), 0.0f);
                other.Move(-interX * push, 0.0f);

            }
            else
            {
                Move(-interX * (1.0f - push), 0.0f);
                other.Move(interX * push, 0.0f);
            }
        }
        else
        {
            if (deltaY > 0.0f) {
                Move(interY * (1.0f - push), 0.0f);
                other.Move(-interY * push, 0.0f);

            }
            else
            {
                Move(-interY * (1.0f - push), 0.0f);
                other.Move(interY  * push, 0.0f);
            }
        }
        return true;
    }


    return false;
}
