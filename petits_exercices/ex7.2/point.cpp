#include "point.hpp"

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