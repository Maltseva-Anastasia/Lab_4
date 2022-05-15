#include "GameHealth.h"

GameHealth::GameHealth(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Texture& texture)
  : GameObject(pos, s)
{
  setSprite(texture);
}

void GameHealth::draw(sf::RenderWindow& win)
{
  win.draw(getSprite());
}
