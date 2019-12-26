
#include "Rectangle.hpp"
 
    Rectangle::Rectangle(Point p1, Point p2, Point p3, Point p4) {
       if (IsRectangle(p1,p2,p3,p4)) {

    } else if (IsRectangle(p2, p3, p1, p4)) {
        std::swap(p2, p1); std::swap(p3,p2);
    } else if (IsRectangle(p3, p1, p2, p4)) {
        std::swap(p3, p1); std::swap(p3,p2);
    } else {
        throw std::logic_error("not rectangle");
    }
    this->points[0] = p1;
    this->points[1] = p2;
    this->points[2] = p3;
    this->points[3] = p4; 
    }
    double Rectangle::getSquare() {
    
	return length(this->points[0],this->points[1])*length(this->points[0],this->points[3]);
    }
            void Rectangle::print(std::ostream& os) const {
    os << "Rectangle p1: ";
    for (int i = 0; i < 4; ++i) {
        os << this->points[i] << "p" << i+1 <<" ";
    }
    os << std::endl;
    }

void Rectangle::scan(std::istream &is) {
    Point p1,p2,p3,p4;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Rectangle(p1,p2,p3,p4);
}
Rectangle::Rectangle(std::istream &is) {
    Point p1,p2,p3,p4;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Rectangle(p1,p2,p3,p4);
}
Point Rectangle::getCenter()  {

    Point p;
    p.x = 0;
    p.y = 0;
    for (size_t i = 0; i < 4; ++i) {
        p = p+(points[i]/4);
    }
    return p;
}