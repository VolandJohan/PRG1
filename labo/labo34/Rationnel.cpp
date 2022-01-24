#include "Rationnel.hpp"
#include <sstream>

using Uint = uintmax_t;

/* constructeurs */
Rationnel::Rationnel() {
    negatif = false;
    numerateur = 1;
    denominateur = 1;
}
Rationnel::Rationnel(Uint& num, Uint& denom) {
    negatif = false;
    numerateur = num;
    denominateur = denom;

    // diviser les valeurs pour éviter d'avoir des valeurs trop grandes
    pgdc();
}
Rationnel::Rationnel(Uint& num, Uint& denom, bool& neg) {
    negatif = neg;
    numerateur = num;
    denominateur = denom;

    // diviser les valeurs pour éviter d'avoir des valeurs trop grandes
    pgdc();
}

/* opérateurs arithmétiques */
/*
Rationnel operator-=(const Rationnel& right);    
Rationnel operator*=(const Rationnel& right);
Rationnel operator/=(const Rationnel& right);
friend Rationnel operator+(Rationnel left, const Rationnel& right);
friend Rationnel operator-(Rationnel left, const Rationnel& right);
friend Rationnel operator*(Rationnel left, const Rationnel& right);
friend Rationnel operator/(Rationnel left, const Rationnel& right);*/
Rationnel Rationnel::operator+=(Rationnel& right) {
    /* test du dénominateur */
    if (denominateur != right.denominateur) {
        // multiplier les numérateurs avec les dénominateurs
        numerateur *= right.denominateur;
        right.numerateur *= denominateur;
        // multiplier les dénominateurs entre eux
        denominateur *= right.denominateur;
    }

    // tester si l'un des nombres à un signe
    if (negatif != right.negatif) { // si les signes sont différents ...
        // tester quel numérateur est supérieur
        if (numerateur < right.numerateur) {
            negatif = !(negatif);
            numerateur = right.numerateur - numerateur;
        } else {
            numerateur -= right.numerateur;
        }
    } else { // si les signes sont identiques, on fait une simple addition
        numerateur += right.numerateur;
    }

    pgdc();
    return *this;
}

Rationnel Rationnel::operator-=(Rationnel& right) {
    /* test du dénominateur */
    if (denominateur != right.denominateur) {
        // multiplier les numérateurs avec les dénominateurs
        numerateur *= right.denominateur;
        right.numerateur *= denominateur;
        // multiplier les dénominateurs entre eux
        denominateur *= right.denominateur;
    }

    /* calculs en fonction de qui est négatif */
    if (numerateur == right.numerateur) {
        numerateur = 0;
        negatif = false;
    } else if (numerateur > right.numerateur) {
        if (negatif && right.negatif) {
            numerateur -= right.numerateur;
        } else if (negatif==false && right.negatif==false) {
            numerateur -= right.numerateur;
        } else {
            numerateur += right.numerateur;
        }
    } else {
        if (right.negatif && negatif == false) {
            numerateur += right.numerateur;
        } else {
            numerateur = right.numerateur - numerateur;
            negatif = !(negatif);
        }
    }

    pgdc();
    return *this;
}

// opérateur de lecture
std::ostream& operator<<(std::ostream& os, const Rationnel& val) {
    if (val.negatif) {
        os << '-';
    }
    
    os << val.numerateur << '/' << val.denominateur;
    return os;
}

/**
 * @brief Calcul le PGDC du numérateur et du dénominateur et l'applique à ces derniers
 * 
 */
void Rationnel::pgdc() {
    Uint nb1 = numerateur;
    Uint nb2 = denominateur;

    // calcul du PGDC
    while (nb1 != nb2) {
        if (nb1 > nb2) {
            nb1 -= nb2;
        } else {
            nb2 -= nb1;
        }
    }
    
    // application du PGDC
    numerateur /= nb1;
    denominateur /= nb1;
    if (numerateur == denominateur) {
        numerateur = 1;
        denominateur = 1;
    }
}