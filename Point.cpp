#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include "Figure.hpp"
std::istream& operator >> (std::istream& is, Point& p) {
  return is >> p.x >> p.y;
}

std::ostream& operator<< (std::ostream& os, const Point& p) {
  return os << p.x << " " << p.y;
}
Point operator+(Point left, Point right) {
    Point p;
    p.x = left.x+right.x;
    p.y = left.y+right.y;
        return p;

}
Point operator+(Point left, int right) {
    Point p;
    p.x = left.x+right;
    p.y = left.y+right;
        return p;

}
Point operator-(Point left, Point right) {
    Point p;
    p.x = left.x-right.x;
    p.y = left.y-right.y;
        return p;

}
Point operator-(Point left, double right) {
    Point p;
    p.x = left.x-right;
    p.y = left.y-right;
        return p;

}
Point operator/(Point left, double right) {
    Point p;
    p.x = left.x/right;
    p.y = left.y/right;
        return p;

}
Point operator*(Point left, double right) {
    Point p;
    p.x = left.x*right;
    p.y = left.y*right;
    return p;
}
double length(Point left, Point right) {
    return sqrt((left.x-right.x)*(left.x-right.x)+(left.y-right.y)*(left.y-right.y));
}
bool IsOrthogonal(Point a, Point b, Point c)
{
    return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}
bool IsParallel(Point a, Point b, Point c, Point d)
{
    Point a1 = a-b; 
    Point a2 = c-d;  
    return ((a1.x*a2.x+a1.y*a2.y)/(length(a,b)*length(c,d))<=-1 || (a1.x*a2.x+a1.y*a2.y)/(length(a,b)*length(c,d))>=1);
}
int IsRectangle(Point a, Point b, Point c, Point d)
{
    return
        IsOrthogonal(a, b, c) &&
        IsOrthogonal(b, c, d) &&
        IsOrthogonal(c, d, a);
}