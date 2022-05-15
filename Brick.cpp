#include "Brick.h"

Brick::Brick(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName)
  : GameObject(pos, s)
{
  setTexture(fileName);
  setSprite(getTexture());
  maxHealth = health = 3;
}

Brick::Brick(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Texture& texture)
  : GameObject(pos, s)
{
  setSprite(texture);
  maxHealth = health = 2;
}

void Brick::draw(sf::RenderWindow& win)
{
  if(isAlive())
    win.draw(getSprite());
}

void Brick::update(void)
{
  setSpriteColor(sf::Color(255, 255, 255, 255  * (0.3 + 0.7 * (float(health) / maxHealth))));
}

void Brick::changeHP(int hp)
{
  health += hp;
  if (health > maxHealth)
    health = maxHealth;
  else if (health < 0)
    health = 0;
}

