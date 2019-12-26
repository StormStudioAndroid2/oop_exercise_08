#pragma once

#include <vector>
#include "Figure.hpp"
class Rhombus: public Figure {
    private:
        Point points[4];
    public:
        Rhombus() = default;
        Rhombus(Point p1, Point p2, Point p3, Point p4);
        Rhombus(std::istream& is);

         double getSquare();
        Point getCenter();
         void print(std::ostream& os) const;
         void scan(std::istream &is);
};