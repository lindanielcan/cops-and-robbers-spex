#include<iostream>
#include "fraction.h"

using namespace std;

// static here tells the compiler that only functions in this file can access
// the function; functions in other files don’t see it

static int gcd(int a, int b)
{
    int r;
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
Fraction::Fraction(int n,int d)
{
    int g;
    if (d < 0)
    {
        n = -n;
        d = -d;
    }
g = gcd(n,d);
n /= g;
d /= g;

num = n;
den = d;
}
Fraction::~Fraction(void){}

Fraction Fraction::operator+(Fraction rhs) 
{
 int s,t;

 s = num * rhs.den + den * rhs.num;
 t = den * rhs.den;

 return Fraction(s,t);
}
Fraction Fraction::operator-(Fraction rhs) 
{
 int s,t;

 s = num * rhs.den - den * rhs.num;
 t = den * rhs.den;

 return Fraction(s,t);
}
Fraction Fraction::operator/(Fraction rhs) 
{
 int s,t;

 s = num * rhs.den;
 t = den * rhs.num;

 return Fraction(s,t);
}
Fraction Fraction::operator*(Fraction rhs) 
{
 int s,t;

 s = num * rhs.num;
 t = den * rhs.den;

 return Fraction(s,t);
}

bool Fraction::operator==(Fraction rhs)
{
    int s,t;
    s = num * rhs.den;
    t = den * rhs.num;

    return s == t;
}

bool Fraction::operator!=(Fraction rhs)
{
    int s,t;
    s = num * rhs.den;
    t = den * rhs.num;

    return s != t;
}

bool Fraction::operator>(Fraction rhs)
{
    int s,t;
    s = num * rhs.den;
    t = den * rhs.num;

    return s > t;
}

bool Fraction::operator<(Fraction rhs)
{
    int s,t;
    s = num * rhs.den;
    t = den * rhs.num;

    return s < t;
}
istream &operator>>(istream &is,Fraction &f) {

char slash;
is >> f.num >> slash >> f.den;
return is;
}

 ostream &operator<<(ostream &os,Fraction &f) {

os << f.num << " / " << f.den; // those are spaces next to the slash!

 return os;
 }