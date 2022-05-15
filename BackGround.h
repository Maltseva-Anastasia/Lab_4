#pragma once
#include "GameObject.h"
class BackGround : GameObject
{
public:
  BackGround(const sf::RenderWindow& win, const std::string& fileName);
  BackGround(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName);
  void draw(sf::RenderWindow& win);
};

