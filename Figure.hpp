#pragma once

#include <vector>
#include <numeric>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
struct Point {
    double x = 0;
    double y = 0;
};
std::istream& operator >> (std::istream& is, Point& p);
std::ostream& operator<< (std::ostream& os, const Point& p);
Point operator+(Point left, Point right);
Point operator+(Point left, int right);
Point operator-(Point left, Point right);
Point operator-(Point left, double right);
Point operator/(Point left, double right);

Point operator*(Point left, double right);
bool IsOrthogonal(Point a, Point b, Point c);
int IsRectangle(Point a, Point b, Point c, Point d);
bool IsParallel(Point a, Point b, Point c, Point d);
double length(Point left, Point right);
class Figure {
    
    public:
        virtual double getSquare() = 0;
        virtual Point getCenter() = 0;
            virtual ~Figure() = default;
        
        virtual void print(std::ostream& os) const = 0;
        virtual void scan(std::istream &is) = 0;
};
std::ostream& operator << (std::ostream& os, const Figure& fig);
std::istream& operator >> (std::istream& is, Figure& fig);