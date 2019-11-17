#include <iostream>
#include "point.h"

using namespace std;



Point Point::operator+(Point rhs)
{
    Fraction i, j;
    i = x + rhs.x;
    j = y + rhs.y;

    return Point(i, j);
}
Point Point::operator-(Point rhs)
{
    Fraction i, j;
    i = x - rhs.x;
    j = y - rhs.y;
    return Point(i, j);
}
Point Point::operator*(Fraction rhs)
{
    int r;
    Fraction i, j;
    i = i * r;
    j = j * r;
    return Point(i, j);
}

Fraction Point::operator*(Point rhs)
{
    Fraction k;
    k = (x * rhs.y) - (y * rhs.x);
    return k;
}
