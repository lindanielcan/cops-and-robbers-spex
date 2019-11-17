#include <iostream>
#include "point.h"
#include "fraction.h"

using namespace std;

Point::Point(Fraction x, Fraction y)
{
    this -> x = x;
    this -> y = y;
}
Point::~Point(void){}


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

istream &operator>>(istream &is,Point &p) {
char comma, lpar,rpar;
Fraction x,y;

is >> lpar >> x >> comma >> y >> rpar;

p = Point(x,y);
return is;

}

 ostream &operator<<(ostream &os,Point &p) {

os <<  "(" << p.x << " , " << p.y << ")"; // those are spaces next to the slash!

 return os;
 }
