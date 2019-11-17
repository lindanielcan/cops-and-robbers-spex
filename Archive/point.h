#include <iostream>
#ifndef _POINT_H
#define _POINT_H
#include "fraction.h"
using namespace std;

class Point
{
  public:
    Point(Fraction x = Fraction(), Fraction y = Fraction());
    ~Point(void);

    Point operator+(Point rhs);
    Point operator-(Point rhs);
    Point operator*(Fraction rhs);
    Fraction operator*(Point rhs);

    friend istream &operator>>(istream &, Point &);
    friend ostream &operator<<(ostream &, Point &);

  private:
    Fraction x, y;
};
#endif
