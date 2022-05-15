#pragma once
#include "GameObject.h"
#include "MovingObject.h"
#include "Platform.h"
#include "Brick.h"
#include "BrickWall.h"
class Ball : public GameObject, public MovingObject
{
private:
  Platform* platform;
  bool stuck;
  bool fellDown;
public:
  Ball(Platform* platform, const std::string& fileName);
  void setDefaultSize(void);
  void setDefaultPosition(void);
  void move(double time);
  void move(const sf::Vector2f& vec);
  void draw(sf::RenderWindow& win);
  void update(double time, std::list<BrickWall*>& brickWalls);
  const sf::Vector2f getStartSpeed(void);
  void checkBorders(void);
  void collide(Brick& obj2);
  void collide(BrickWall& wall);
  void collide(const Platform& obj2);
  bool isFellDown(void) const { return fellDown; }
  void returnBack(void) { fellDown = false; }
};

