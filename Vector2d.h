#pragma once
class Vector2d
{
private:
  double x;
  double y;
public:
  Vector2d(void);
  Vector2d(double x, double y);
  Vector2d(const Vector2d& vec);
  double getX(void);
  double getY(void);
  Vector2d& operator=(const Vector2d& vec);
  Vector2d operator+(const Vector2d& vec);
  Vector2d operator-(const Vector2d& vec);
  Vector2d operator*(double num);
  Vector2d operator/(double num);
  Vector2d& operator+=(const Vector2d& vec);
  Vector2d& operator-=(const Vector2d& vec);
  Vector2d& operator*=(double num);
  Vector2d& operator/=(double num);
  friend Vector2d& operator*(double num, const Vector2d& vec);


};

