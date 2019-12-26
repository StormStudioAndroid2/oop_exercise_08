#pragma once

#include <vector>
#include "Figure.hpp"
class Rectangle: public Figure {
    private: Point points[4];
    public:
     Rectangle() = default;
        Rectangle(Point p1, Point p2, Point p3, Point p4);
    Rectangle(std::istream& is);

         double getSquare();
        Point getCenter();
         void print(std::ostream& os) const;
         void scan(std::istream &is);
};