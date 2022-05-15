#include "HealthBar.h"

HealthBar::HealthBar(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, int mHealth) 
  : GameObject(pos, s)
{
  health = maxHealth = mHealth;
  setTexture(fileName);
  sf::Vector2f oneHealthSize = sf::Vector2f(s.x / maxHealth, s.y);
  for (int i = 0; i < maxHealth; i++)
  {
    healthList.push_back(new GameHealth(sf::Vector2f(pos.x + oneHealthSize.x * i, pos.y), oneHealthSize, getTexture()));
  }
}

HealthBar::~HealthBar()
{
  for (auto healthPoit : healthList)
  {
    delete healthPoit;
  }
  healthList.clear();
}

void HealthBar::draw(sf::RenderWindow& win)
{
  for (auto healthPoit : healthList)
  {
    win.draw(healthPoit->getSprite());
  }
}

void HealthBar::hit(void)
{
  if(health > 0)
  {
    health--;
    delete healthList.back();
    healthList.pop_back();
  }
}