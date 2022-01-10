#ifndef POINT_HPP
#define POINT_HPP

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
    Point operator+(const Point& droit) const;
};
#endif