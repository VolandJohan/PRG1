#include <iostream>
#include "point.hpp"

int main() {
    Point pt(2.0f, 3.0f);
    pt.deplacer(5.0f, 5.0f);

    std::cout << pt.abscisse() << std::endl;
    std::cout << pt.ordonnee() << std::endl;
}