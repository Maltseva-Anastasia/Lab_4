#include "Platform.h"

Platform::Platform(const sf::RenderWindow& win, const std::string& fileName) : 
  MovingObject(sf::Vector2f(0, 0), sf::Vector2f(0, 0), sf::Vector2f(win.getSize()))
{
  setDefaultSize();
  setDefaultPosition();
  setTexture(fileName);
  setSprite(getTexture());
}

void Platform::draw(sf::RenderWindow& win)
{
  win.draw(getSprite());
}

void Platform::setDefaultPosition()
{
    setPosition(sf::Vector2f((getMoveBorder().lowerRight.x - getMoveBorder().upperLeft.x - getSize().x) / 2,
                              getMoveBorder().lowerRight.y - getMoveBorder().upperLeft.y - getSize().y));
}

void Platform::setDefaultSize()
{
  setSize(sf::Vector2f(float((getMoveBorder().lowerRight.x - getMoveBorder().upperLeft.x) * 0.15),
                       float((getMoveBorder().lowerRight.y - getMoveBorder().upperLeft.y) * 0.05)));
}

void Platform::move(double time)
{
  setPosition(getPosition() + sf::Vector2f(float(getSpeed().x * time), float(getSpeed().y * time)));
}

void Platform::update(double time)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    setSpeed(sf::Vector2f(400, 0));
  }
  else
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    setSpeed(sf::Vector2f(-400, 0));
  }
  else
  {
    setSpeed(sf::Vector2f(0, 0));
  }
  move(time);
  checkBorders();
}

void Platform::checkBorders(void)
{
  if (getPosition().x < getMoveBorder().upperLeft.x)
  {
    setPosition(sf::Vector2f(getMoveBorder().upperLeft.x, getPosition().y));
  }
  if (getPosition().x > getMoveBorder().lowerRight.x - getSize().x)
  {
    setPosition(sf::Vector2f(getMoveBorder().lowerRight.x - getSize().x, getPosition().y));
  }
}