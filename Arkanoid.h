#pragma once
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include <string.h>
#include <list>
#include "BackGround.h"
#include "Platform.h"
#include "Ball.h"
#include "Brick.h"
#include "BrickWall.h"
#include "HealthBar.h"
#include <iostream>
#include <fstream>

struct BrickWallDescription
{
  sf::Vector2f relativePosition;
  sf::Vector2f relativeSize;
  sf::Vector2i brickNum;
  sf::Vector2i spaces;
  std::string brickTextureName;

};

struct level
{
  std::string levelName;
  std::string backGroundTextureName;
  std::string PlatformTextureName;
  std::string BallTextureName;
  std::list<BrickWallDescription> brickWallsDescriptions;
};

class Arkanoid
{
private:
  sf::RenderWindow window;
  sf::Clock clock;
  double ellapsedTime;
  BackGround* background;
  Platform* platform;
  Ball* ball;
  HealthBar* health;
  std::list<BrickWall*> brickWalls;
  std::list<level> levels;

public:
  Arkanoid(const std::string& title, int width, int height);
  ~Arkanoid(void);
  void draw(void);
  void go(void);
  void update(void);
  void timeUpdate(void);
  void readLevels(std::ifstream& inputFile);
  void loadLevel(level& newLevel);
};



