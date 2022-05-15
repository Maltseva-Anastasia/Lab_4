#pragma once
#include "GameObject.h"
class GameHealth : public GameObject
{
public:
  GameHealth(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Texture& texture);
  void draw(sf::RenderWindow& win);

};

