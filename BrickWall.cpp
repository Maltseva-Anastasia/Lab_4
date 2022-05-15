#include "BrickWall.h"
#include <iterator>
#include <algorithm>

BrickWall::BrickWall(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName,
  const sf::Vector2i& brickNum, const sf::Vector2i& spaces) : GameObject(pos, s)
{
  setTexture(fileName);
  sf::Vector2f brickSize;
  brickSize.x = (s.x - (brickNum.x - 1) * spaces.x) / brickNum.x;
  brickSize.y = (s.y - (brickNum.y - 1) * spaces.y) / brickNum.y;
  for (int i = 0; i < brickNum.x; i++)
  {
    for (int j = 0; j < brickNum.y; j++)
    {
      bricks.push_back(new Brick
      (sf::Vector2f(getPosition().x + i * (brickSize.x + spaces.x), getPosition().y + j * (brickSize.y + spaces.y)),
        sf::Vector2f(brickSize),
        getTexture()));
    }
  }
}

BrickWall::~BrickWall()
{
  for (auto brick : bricks)
  {
    delete brick;
  }
  bricks.clear();
}

void BrickWall::draw(sf::RenderWindow& win)
{
  for (auto brick : bricks)
  {
    if (brick->isAlive())
      brick->draw(win);
  }
}

void BrickWall::update(void)
{
  auto brick = bricks.begin();

  while (brick != bricks.end())
  {
    if ((*brick)->isAlive()) 
    {
      (*brick)->update();
      brick++;
    }
    else
    {
      delete(*brick);
      bricks.erase(brick++);
    }

  }

  


  /*for (auto brick = bricks.begin(); brick != bricks.end(); brick++)
  {
    if ((*brick)->isAlive())
      (*brick)->update();
    else
    {
      delete(*brick);
      bricks.remove(*brick);
      b
    }
  }*/
}



/*void BrickWall::update(void)
{
  for (auto brick : bricks)
  {
    if (brick->isAlive())
      brick->update();
    //bricks.erase(brick);
  }
}*/
