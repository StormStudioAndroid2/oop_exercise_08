#include "Figure.hpp"

std::ostream& operator << (std::ostream& os, const Figure& fig) {
    fig.print(os);
    return os;
}

std::istream& operator >> (std::istream& is, Figure& fig) {
    fig.scan(is);
    return is;
}