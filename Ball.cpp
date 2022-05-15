#include "Ball.h"
#include <cmath>
#include <cstdlib>
#include <time.h>
#define PI 3.1415926535

Ball::Ball(Platform* platform, const std::string& fileName) :
  MovingObject(sf::Vector2f(0.f, 0.f),platform->getMoveBorder().upperLeft, platform->getMoveBorder().lowerRight),
  platform(platform)
{
  setDefaultSize();
  setDefaultPosition();
  setTexture(fileName);
  setSprite(getTexture());
  stuck = true;
  fellDown = false;
  srand(time(NULL));

}

void Ball::setDefaultSize()
{
  setSize(sf::Vector2f(float((getMoveBorder().lowerRight.x - getMoveBorder().upperLeft.x) * 0.03),
    float((getMoveBorder().lowerRight.x - getMoveBorder().upperLeft.x) * 0.03)));
}

void Ball::setDefaultPosition()
{
  setPosition(sf::Vector2f(platform->getPosition().x + (platform->getSize().x - getSize().x) / 2,
    platform->getPosition().y - getSize().y));
}

void Ball::move(double time)
{
  setPosition(getPosition() + sf::Vector2f(float(getSpeed().x * time), float(getSpeed().y * time)));
}

void Ball::move(const sf::Vector2f& vec)
{
  setPosition(getPosition() + vec);
}

void Ball::draw(sf::RenderWindow& win)
{
  win.draw(getSprite());
}

void Ball::update(double time, std::list<BrickWall*>& brickWalls)
{

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    if (stuck)
    {
      setSpeed(getStartSpeed());
    }
    stuck = false;
  }

  /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
  {
    stuck = true;
  }*/

  if(stuck)
    setDefaultPosition();
  move(time);
  checkBorders();
  if (isCollided(*(this->platform)))
    collide(*(this->platform));
  for (auto brickWall:brickWalls)
    if (isCollided(*brickWall))
      collide(*brickWall);
  //if (is)
  /*{
    setDefaultPosition();
    stuck = true;
  }*/
}

const sf::Vector2f Ball::getStartSpeed(void)
{
  double speedModule = 300;
  

  double angle = (double(rand()) / RAND_MAX) * (2.0 / 3 * PI) + PI / 6;
  return sf::Vector2f(float(speedModule * cos(angle)), -float(speedModule * sin(angle)));
  //return sf::Vector2f(float( 0.f), -float(speedModule));
}

void Ball::checkBorders(void)
{
  if (getPosition().x + getSize().x > getMoveBorder().lowerRight.x)
  {
    reverseSpeedX();
    move(sf::Vector2f((getMoveBorder().lowerRight.x - getPosition().x - getSize().x) * 2, 0.f));
    return;
  }
  if (getPosition().y < getMoveBorder().upperLeft.y)
  {
    reverseSpeedY();
    move(sf::Vector2f(0.0f, (getMoveBorder().upperLeft.y - getPosition().y) * 2));
    return;
  }
  if (getPosition().x < getMoveBorder().upperLeft.x)
  {
    reverseSpeedX();
    move(sf::Vector2f((getMoveBorder().upperLeft.x - getPosition().x) * 2, 0.f));
    return;
  }
  if (getPosition().y + getSize().y > getMoveBorder().lowerRight.y)
  {
    stuck = true;
    fellDown = true;
  }
}

void Ball::collide(Brick& obj2)
{
  float vertical;
  float horizontal;

  if (getSpeed().y >= 0)
    vertical = obj2.getPosition().y - getSize().y - getPosition().y;
  else
    vertical = obj2.getPosition().y + obj2.getSize().y - getPosition().y;
  if (getSpeed().x >= 0)
    horizontal = obj2.getPosition().x - getSize().x - getPosition().x;
  else
    horizontal = obj2.getPosition().x + obj2.getSize().x - getPosition().x;
  if (-getSpeed().x / horizontal > -getSpeed().y / vertical) 
  {
    /*setDefaultPosition();
    stuck = true;*/
    reverseSpeedX();
    move(sf::Vector2f(horizontal * 2, 0.0f));
  }
  else
  {
    reverseSpeedY();
    move(sf::Vector2f(0.0f, vertical * 2));
  }
  obj2.changeHP(-1);
}

void Ball::collide(BrickWall& wall)
{
  for (auto brick : wall.getBricks())
  {
    if (brick->isAlive() && isCollided(*brick))
    {
      collide(*brick);
    }
  }
}


void Ball::collide(const Platform& obj2)
{
  float vertical;
  float horizontal;

  //setDefaultPosition();

  if (getSpeed().y - obj2.getSpeed().y >= 0)
    vertical = obj2.getPosition().y - getSize().y - getPosition().y;
  else
    vertical = obj2.getPosition().y + obj2.getSize().y - getPosition().y;
  if (getSpeed().x - obj2.getSpeed().x >= 0)
    horizontal = obj2.getPosition().x - getSize().x - getPosition().x;
  else
    horizontal = obj2.getPosition().x + obj2.getSize().x - getPosition().x;
  if (-(getSpeed().x - obj2.getSpeed().x) / horizontal > -(getSpeed().y - obj2.getSpeed().y) / vertical)
  {
    reverseSpeedX();
    move(sf::Vector2f(horizontal * 2, 0.0f));
  }
  else
  {
    reverseSpeedY();
    move(sf::Vector2f(0.0f, vertical * 2));
  }

  double part = (getPosition().x + getSize().x / 2 - obj2.getPosition().x - obj2.getSize().x / 2) / obj2.getSize().x * 2;

  double initialSpeedModule = getSpeedModule();
  if (part > 0.6)
    setSpeed(sf::Vector2f((getSpeed().x + 100), getSpeed().y));
  else if (part < -0.6)
    setSpeed(sf::Vector2f((getSpeed().x - 100), getSpeed().y));
  else 
    setSpeed(sf::Vector2f((getSpeed().x), getSpeed().y - 100));

  double finalSpeedModule = getSpeedModule();
  if (finalSpeedModule != 0)
    setSpeed(sf::Vector2f(float(getSpeed().x * initialSpeedModule / finalSpeedModule),
      float(getSpeed().y * initialSpeedModule / finalSpeedModule)));
}

