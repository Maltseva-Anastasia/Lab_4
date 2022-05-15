#include "BackGround.h"
#include <iostream>

BackGround::BackGround(const sf::RenderWindow& win, const std::string& fileName) :
  GameObject(sf::Vector2f(0, 0), sf::Vector2f((float)win.getSize().x, (float)win.getSize().y))
{
  setTexture(fileName);
  setSprite(getTexture());
}

BackGround::BackGround(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName)
  : GameObject(pos, s)
{
  setTexture(fileName);
  setSprite(getTexture());
}

void BackGround::draw(sf::RenderWindow& win)
{
  win.draw(getSprite());
}