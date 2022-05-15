#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"

struct MoveBorder
{
  sf::Vector2f upperLeft;
  sf::Vector2f lowerRight;
};

class MovingObject
{
private:
  sf::Vector2f speed;
  MoveBorder moveBorder;
public:
  MovingObject(const sf::Vector2f& spd,const sf::Vector2f& upperLeft,const sf::Vector2f& lowerRight);
  void setSpeed(const sf::Vector2f& spd);
  void setMoveBorder(const sf::Vector2f& upperLeft, const sf::Vector2f& lowerRight);
  const MoveBorder& getMoveBorder(void) { return moveBorder; }
  const sf::Vector2f& getSpeed(void) const { return speed; }
  double getSpeedModule() { return sqrt(getSpeed().x * getSpeed().x + getSpeed().y * getSpeed().y); }
  virtual void move(double time) = 0;
  void reverseSpeedX(void) { speed.x *= -1; }
  void reverseSpeedY(void) { speed.y *= -1; }
};

