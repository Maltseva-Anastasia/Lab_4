#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include <string.h>
#include <iostream>
class GameObject
{
private:
  sf::Vector2f position;
  sf::Vector2f size;
  sf::Texture texture;
  sf::Sprite sprite;
public:
  GameObject(const sf::Vector2f& pos, const sf::Vector2f& s);
  GameObject(void);
  virtual void draw(sf::RenderWindow& win) = 0;
  void setPosition(const sf::Vector2f& pos);
  void setSize(const sf::Vector2f& s);
  void setTexture(const std::string& fileName) { texture.loadFromFile(fileName); }
  void setSprite(const sf::Texture& texture);
  void setSpriteColor(const sf::Color col) { sprite.setColor(col); }
  const sf::Vector2f& getPosition() const { return position; }
  const sf::Vector2f& getSize() const { return size; }
  const sf::Texture& getTexture() const { return texture; }
  const sf::Sprite& getSprite() const { return sprite; }
  bool isCollided(const GameObject& obj2) const;
};

