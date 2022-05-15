#pragma once
#include "GameObject.h"
#include "MovingObject.h"
class Platform : public GameObject, public MovingObject
{
public:
  Platform(const sf::RenderWindow& win, const std::string& fileName);
  void draw(sf::RenderWindow& win);
  void setDefaultPosition(void);
  void setDefaultSize(void);
  virtual void move(double time);
  void update(double time);
  void checkBorders(void);
};

