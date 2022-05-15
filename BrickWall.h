#pragma once
#include "GameObject.h"
#include "Brick.h"
#include <list>
class BrickWall : public GameObject
{
private:
  std::list<Brick*> bricks;
public:
  BrickWall(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName,
    const sf::Vector2i& brickNum, const sf::Vector2i& spaces);
  ~BrickWall();
  std::list<Brick*>& getBricks(void) { return bricks; }
  void draw(sf::RenderWindow& win);
  void update(void);
  bool isEmpty(void) { return bricks.empty(); }
};

