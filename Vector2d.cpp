#include "Vector2d.h"

Vector2d::Vector2d()
{
  x = 0;
  y = 0;
}

Vector2d::Vector2d(double x, double y)
{
  this->x = x;
  this->y = y;
}

Vector2d::Vector2d(const Vector2d& vec)
{
  x = vec.x;
  y = vec.y;
}

double Vector2d::getX()
{
  return x;
}

double Vector2d::getY()
{
  return y;
}

Vector2d& Vector2d::operator=(const Vector2d& vec) 
{
  x = vec.x;
  y = vec.y;
  return *this;
}

Vector2d Vector2d::operator+(const Vector2d& vec) 
{
  Vector2d newVector(x + vec.x, y + vec.y);
  return newVector;
}

Vector2d Vector2d::operator-(const Vector2d& vec)
{
  Vector2d newVector(x - vec.x, y - vec.y);
  return newVector;
}

Vector2d Vector2d::operator*(double num)
{
  Vector2d newVector(x * num, y * num);
  return newVector;
}

Vector2d Vector2d::operator/(double num)
{
  Vector2d newVector(x / num, y / num);
  return newVector;
}

Vector2d& Vector2d::operator+=(const Vector2d& vec)
{
  x += vec.x;
  y += vec.y;
  return *this;
}

Vector2d& Vector2d::operator-=(const Vector2d& vec)
{
  x -= vec.x;
  y -= vec.y;
  return *this;
}

Vector2d& Vector2d::operator*=(double num)
{
  x *= num;
  y *= num;
  return *this;
}

Vector2d& Vector2d::operator/=(double num)
{
  x /= num;
  y /= num;
  return *this;
}

Vector2d& operator*(double num, const Vector2d& vec)
{
  Vector2d newVec(num * vec.x, num * vec.y);
  return newVec;
}



