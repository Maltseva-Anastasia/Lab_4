#pragma once
#include "GameObject.h"
#include "GameHealth.h"
#include <list>
class HealthBar : public GameObject
{
private:
  int maxHealth;
  int health;
  std::list<GameHealth*> healthList;
public:
  HealthBar(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, int mHealth);
  void hit(void);
  bool isAlive(void) { return health > 0; }
  ~HealthBar();
  void draw(sf::RenderWindow& win);
};

