#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <numbers>

const float PI = M_PI;

class Point {
private:
    float x, y;
public:
    // constructeur
    Point(float abscisse, float ordonnee);
    // fonctions membres
    void deplacer(float deplacement_x, float deplacement_y);
    float abscisse() const; // ne modifie pas les valeurs
    float ordonnee() const;
    float rho() const;
    float theta() const;
    void rotation(float angle);
    Point operator+(const Point& droit) const;
};
#endif