#include "GameObject.h"


GameObject::GameObject(const sf::Vector2f& pos, const sf::Vector2f& s)
{
  setPosition(pos);
  setSize(s);
}

GameObject::GameObject()
{
  setPosition(sf::Vector2f(0, 0));
  setSize(sf::Vector2f(100, 100));
}

void GameObject::setPosition(const sf::Vector2f& pos)
{
  position = pos;
  sprite.setPosition(pos);
}

void GameObject::setSize(const sf::Vector2f& s) { 
  size = s;
  sprite.setScale(size.x / sprite.getLocalBounds().width,
    size.y / sprite.getLocalBounds().height);
}

void GameObject::setSprite(const sf::Texture& texture)
{
  //sprite.setColor(sf::Color::Blue);
  sprite.setTexture(texture);
  sprite.setScale(size.x / sprite.getLocalBounds().width,
    size.y / sprite.getLocalBounds().height);
}

bool GameObject::isCollided(const GameObject& obj2) const
{
  if ((position.x + size.x > obj2.position.x) && (position.x < obj2.position.x + obj2.size.x) && 
    (position.y + size.y > obj2.position.y) && (position.y < obj2.position.y + obj2.size.y))
    return true;
  return false;
}