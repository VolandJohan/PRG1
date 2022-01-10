#include <iostream>
#include "point.hpp"

using namespace std;

int main() {
    Point pt(2.0f, 3.0f);
    Point pt2(1.0f, 67.0f);
    pt.deplacer(5.0f, 5.0f);

    cout << pt.abscisse() << " " << pt.ordonnee() << endl;

    Point pt3 = pt + pt2;
    cout << pt3.abscisse() << " " << pt3.ordonnee() << endl;
}