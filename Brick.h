#pragma once
#include "GameObject.h"
class Brick : public GameObject
{
private:
  int health;
  int maxHealth;
public:
  Brick(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName);
  Brick(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Texture& texture);
  void draw(sf::RenderWindow& win);
  void update(void);
  void changeHP(int hp);
  bool isAlive() const { return health > 0 ? true : false; }
};
