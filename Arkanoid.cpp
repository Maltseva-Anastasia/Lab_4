#include "Arkanoid.h"
#include <sstream>
#include <iostream>


Arkanoid::Arkanoid(const std::string& title, int width, int height)
  : window(sf::VideoMode(width, height), title), ellapsedTime(0)
{
  health = new HealthBar(sf::Vector2f(0, 0),
    sf::Vector2f(window.getSize().x * 0.12, window.getSize().y * 0.08), "images//snowflake.png", 3);
}

Arkanoid::~Arkanoid()
{
  delete background;
  delete platform;
  delete ball;
  for (auto brickWall : brickWalls)
    delete brickWall;
  brickWalls.clear();
}

void Arkanoid::draw()
{
  window.clear();
  background->draw(window);
  for (auto brickWall : brickWalls)
    brickWall->draw(window);;
  
  platform->draw(window);
  ball->draw(window);
  health->draw(window);
  window.display();
}

void Arkanoid::update()
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      window.close();
  }
  timeUpdate();
  platform->update(ellapsedTime);
  ball->update(ellapsedTime, brickWalls);
  if (ball->isFellDown())
  {
    health->hit();
    ball->returnBack();
  }

  auto brickWall = brickWalls.begin();

  while (brickWall != brickWalls.end())
  {
    if (!(*brickWall)->isEmpty())
    {
      (*brickWall)->update();
      brickWall++;
    }
    else
    {
      delete(*brickWall);
      brickWalls.erase(brickWall++);
    }
  }
}

void Arkanoid::go()
{
  loadLevel(levels.front());
  while (window.isOpen())
  {
    if (!health->isAlive())
      break;
    if (brickWalls.empty())
    {
      levels.pop_front();
      if (levels.empty())
      {
        break;
      }
      loadLevel(levels.front());
    }
    update();
    draw();
  }
}

void Arkanoid::timeUpdate()
{
  ellapsedTime = clock.getElapsedTime().asSeconds();
  clock.restart();
}

void Arkanoid::readLevels(std::ifstream& inputFile)
{
  level tempLevel;
  BrickWallDescription tempBrickWallDescription;
  std::string readedLine;
  std::vector<std::string> words;
  std::istringstream stream_line;
  do {
    words.clear();
    if (inputFile.fail() || inputFile.eof() || inputFile.bad())
      return;
    getline(inputFile, readedLine);
    stream_line = std::istringstream(readedLine);
    std::copy(std::istream_iterator<std::string>(stream_line), std::istream_iterator<std::string>(), std::back_inserter(words));
    if (words.empty())
      continue;

    
    if (words[0] == "new_level")
    {
      do {
        words.clear();
        do
        {
          if (inputFile.fail() || inputFile.eof() || inputFile.bad())
            return;
          getline(inputFile, readedLine);
          stream_line = std::istringstream(readedLine);
          std::copy(std::istream_iterator<std::string>(stream_line), std::istream_iterator<std::string>(), std::back_inserter(words));
        } while (words.empty());
        if (words[0] == "level_name")
        {
          
          for (auto word = words.begin() + 1; word < words.end(); word++)
            tempLevel.levelName += *word + " ";
        }
        else if (words[0] == "back")
        {
          tempLevel.backGroundTextureName = words[1];
        }
        else if (words[0] == "platform")
        {
          tempLevel.PlatformTextureName = words[1];
        }
        else if (words[0] == "ball")
        {
          tempLevel.BallTextureName = words[1];
        }
        else if (words[0] == "brick_wall")
        {
          do
          {
            words.clear();
            do
            {
              
              if (inputFile.fail() || inputFile.eof() || inputFile.bad())
                return;
              getline(inputFile, readedLine);
              stream_line = std::istringstream(readedLine);
              
              std::copy(std::istream_iterator<std::string>(stream_line), std::istream_iterator<std::string>(), std::back_inserter(words));

            } while (words.empty());

            if (words[0] == "brick_texture")
            {
              tempBrickWallDescription.brickTextureName = words[1];
            }
            else if (words[0] == "position")
            {
              tempBrickWallDescription.relativePosition = sf::Vector2f(atof(words[1].c_str()), atof(words[2].c_str()));
            }
            else if (words[0] == "size")
            {
              tempBrickWallDescription.relativeSize = sf::Vector2f(atof(words[1].c_str()), atof(words[2].c_str()));
            }
            else if (words[0] == "brick_num")
            {
              tempBrickWallDescription.brickNum = sf::Vector2i(atoi(words[1].c_str()), atoi(words[2].c_str()));
            }
            else if (words[0] == "spaces")
            {
              tempBrickWallDescription.spaces = sf::Vector2i(atoi(words[1].c_str()), atoi(words[2].c_str()));
            }
            
          } while (words[0] != "end_brick_wall");
          tempLevel.brickWallsDescriptions.push_back(tempBrickWallDescription);
        }
      } while (words[0] != "end_level");
      levels.push_back(tempLevel);
      tempLevel.brickWallsDescriptions.clear();
      

    }


  } while (true);
  
  std::getline(inputFile, readedLine);
  
}

void Arkanoid::loadLevel(level& newLevel)
{
  if(background)
    delete background;
  if (platform)
    delete platform;
  if(ball)
    delete ball;
  for (auto brickWall : brickWalls)
    delete brickWall;
  brickWalls.clear();

  background = new BackGround(window, newLevel.backGroundTextureName);
  platform = new Platform(window, newLevel.PlatformTextureName);
  ball = new Ball(platform, newLevel.BallTextureName);
  for (auto brickWallDescription: newLevel.brickWallsDescriptions)
    brickWalls.push_back(new BrickWall(
      sf::Vector2f(window.getSize().x * brickWallDescription.relativePosition.x, window.getSize().y * brickWallDescription.relativePosition.y),
      sf::Vector2f(window.getSize().x * brickWallDescription.relativeSize.x, window.getSize().y * brickWallDescription.relativeSize.y), 
      brickWallDescription.brickTextureName, brickWallDescription.brickNum, brickWallDescription.spaces));

}

