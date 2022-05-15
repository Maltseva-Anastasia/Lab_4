#include "MovingObject.h"

MovingObject::MovingObject(const sf::Vector2f& spd, const sf::Vector2f& upperLeft, const sf::Vector2f& lowerRight)
{
  speed = spd;
  moveBorder.upperLeft = upperLeft;
  moveBorder.lowerRight = lowerRight;
}

void MovingObject::setSpeed(const sf::Vector2f& spd)
{
  speed = spd;
}

void MovingObject::setMoveBorder(const sf::Vector2f& upperLeft, const sf::Vector2f& lowerRight)
{
  moveBorder.upperLeft = upperLeft;
  moveBorder.lowerRight = lowerRight;
}