#include "Rhombus.hpp"
    
    Rhombus::Rhombus(Point p1, Point p2, Point p3, Point p4) {
       if (length(p1, p2) == length(p1, p4)
        && length(p3, p4) == length(p2, p3)
        && length(p1, p2) == length(p2, p3)) {

    } else if (length(p1, p4) == length(p1, p3)
           && length(p2, p3) == length(p2, p4)
           && length(p1, p4) == length(p2, p4)) {
        std::swap(p2, p3);
    } else if (length(p1, p3) == length(p1, p2)
              && length(p2, p4) == length(p3, p4)
              && length(p1, p2)== length(p2, p4)) {
        std::swap(p3, p4);
    } else {
        throw std::logic_error("not rhombus");
    }
    this->points[0] = p1;
        this->points[1] = p2;
    this->points[2] = p3;
    this->points[3] = p4;

    }
    double Rhombus::getSquare() {
     
	return length(this->points[1],this->points[3])*length(this->points[0],this->points[2])*0.5;
    }
        void Rhombus::print(std::ostream& os) const {
    os << "Rhombus " << std::endl;
    for (int i = 0; i < 4; ++i) {
        os << this->points[i] << std::endl;
    }
        os << std::endl;

    }

void Rhombus::scan(std::istream &is) {
    Point p1,p2,p3,p4;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Rhombus(p1,p2,p3,p4);
}
Rhombus::Rhombus(std::istream &is) {
    Point p1,p2,p3,p4;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Rhombus(p1,p2,p3,p4);
}
Point Rhombus::getCenter()  {

    Point p;
    p.x = 0;
    p.y = 0;
    for (size_t i = 0; i <4; ++i) {
        p = p+(points[i]/4);
    }
    return p;
}