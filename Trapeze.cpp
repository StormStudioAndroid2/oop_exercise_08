#include "Trapeze.hpp"

    
    Trapeze::Trapeze(Point p1, Point p2, Point p3, Point p4) {
       if (IsParallel(p1,p2,p3,p4) 
        && !IsParallel(p1,p3,p2,p4)) {
        std::swap(p2, p3);

    } else if (!IsParallel(p1,p2,p3,p4) 
        && IsParallel(p1,p3,p2,p4)) {

    
    } else {
        throw std::logic_error("not Trapeze");
    }
    this->points[0] = p1;
    this->points[1] = p2;
    this->points[2] = p3;
    this->points[3] = p4; 
    }
    double Trapeze::getSquare() {

        return (length(this->points[0],this->points[2])+length(this->points[1],this->points[3]))*fabs((this->points[0].y-this->points[1].y))*(0.5);
    }
    void Trapeze::print(std::ostream& os) const {
    os << "Trapeze ";
    for (int i = 0; i < 4; ++i) {
        os << this->points[i] << " p" << i+1 <<" ";
    }
        os << std::endl;

    }

void Trapeze::scan(std::istream &is) {
    Point p1,p2,p3,p4;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Trapeze(p1,p2,p3,p4);
}
Trapeze::Trapeze(std::istream &is) {
    Point p1,p2,p3,p4;
    is >> p1 >> p2 >> p3 >> p4;
    *this = Trapeze(p1,p2,p3,p4);
}
Point Trapeze::getCenter()  {

    Point p;
    p.x = 0;
    p.y = 0;
    for (size_t i = 0; i <4; ++i) {
        p = p+(points[i]/4);
    }
    return p;
}