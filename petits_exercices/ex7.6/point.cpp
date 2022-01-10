#include "point.hpp"
#include <cmath>

// définir constructeur (par affectation)
Point::Point(float abscisse, float ordonnee){
    x = abscisse;
    y = ordonnee;
};

/*constructeur par liste
Point::Point(float abscisse, float ordonnee) : x(abscisse), y(ordonnee) {}*/

void Point::deplacer(float deplacement_x, float deplacement_y) {
    x += deplacement_x;
    y += deplacement_y;
}

float Point::abscisse() const {
    return x;
}
float Point::ordonnee() const {
    return y;
}

float Point::rho() const {
    return hypot(x, y);
}
float Point::theta() const {
    if (y < 0.0f) {
        return float(atan2(y, x)) + 2.0f * PI;
    } else {
        return float(atan2(y, x));
    }
}

void Point::rotation(float angle) {
    float r = rho(), t = theta() + angle;
    x = r * cos(t);
    y = r * sin(t);
}

Point Point::operator+(const Point& droit) const {
    Point tmp = *this;
    tmp.x += droit.x;
    tmp.y += droit.y;
    return tmp;
}