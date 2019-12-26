#pragma once

#include <vector>
#include "Figure.hpp"
class Trapeze: public Figure {
    private:
        Point points[4];
    public:
        Trapeze() = default;
        Trapeze(Point p1, Point p2, Point p3, Point p4);
        Trapeze(std::istream& is);

         double getSquare();
        Point getCenter();
         void print(std::ostream& os) const;
         void scan(std::istream &is);
};