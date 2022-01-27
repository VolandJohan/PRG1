#include "Rationnel.hpp"
#include <sstream>

using Uint = uintmax_t;

/* constructeurs */
Rationnel::Rationnel() {
    negatif = false;
    numerateur = Uint(0);
    denominateur = Uint(0);
}
Rationnel::Rationnel(const Uint &num) {
    negatif = false;
    numerateur = num;
    denominateur = Uint(1);
}
Rationnel::Rationnel(const Uint &num, const Uint &denom) {
    negatif = false;
    numerateur = num;
    denominateur = denom;

    // diviser les valeurs pour éviter d'avoir des valeurs trop grandes
    pgdc();
}
Rationnel::Rationnel(const Uint &num, const Uint &denom, const bool &neg) {
    negatif = neg;
    numerateur = num;
    denominateur = denom;

    // diviser les valeurs pour éviter d'avoir des valeurs trop grandes
    pgdc();
}

/* opérateurs arithmétiques */
Rationnel Rationnel::operator+=(const Rationnel& right) {
    Uint num_temp = right.numerateur;
    Uint denom_temp = right.denominateur;
    bool neg_temp = right.negatif;

    /* test du dénominateur */
    if (denominateur != denom_temp) {
        // multiplier les numérateurs avec les dénominateurs
        numerateur *= denom_temp;
        num_temp *= denominateur;
        // multiplier les dénominateurs entre eux
        denominateur *= denom_temp;
    }

    // tester si l'un des nombres à un signe
    if (negatif != neg_temp) { // si les signes sont différents ...
        // tester quel numérateur est supérieur
        if (numerateur < num_temp) {
            negatif = !(negatif);
            numerateur = num_temp - numerateur;
        } else {
            numerateur -= num_temp;
        }
    } else { // si les signes sont identiques, on fait une simple addition
        numerateur += num_temp;
    }

    pgdc();
    return *this;
}

Rationnel Rationnel::operator-=( const Rationnel& right) {
    Uint num_temp = right.numerateur;
    Uint denom_temp = right.denominateur;
    bool neg_temp = right.negatif;
    
    /* test du dénominateur */
    if (denominateur != denom_temp) {
        // multiplier les numérateurs avec les dénominateurs
        numerateur *= denom_temp;
        num_temp *= denominateur;
        // multiplier les dénominateurs entre eux
        denominateur *= denom_temp;
    }

    /* calculs en fonction de qui est négatif */

    if (numerateur > num_temp) {
        if (negatif == false && neg_temp == false || negatif == true && neg_temp == true) {
            numerateur -= num_temp;
        } else {
            numerateur += num_temp;
        }
    } else if (numerateur < num_temp) {
        if (negatif == false && neg_temp == false || negatif == true && neg_temp == true) {
            numerateur = num_temp - numerateur;
            negatif = !(negatif);
        } else {
            numerateur += num_temp;
        }
    } else {
        negatif = false;
        numerateur = 0;
        denominateur = 0;
    }

    pgdc();
    return *this;
}

Rationnel Rationnel::operator*=(const Rationnel& right) {
    numerateur *= right.numerateur;
    denominateur *= right.denominateur;
    // gestion du signe
    if (negatif && right.negatif) {
        negatif = false;
    } else if (right.negatif) {
        negatif = true;
    }
    pgdc();
    return *this;
}

Rationnel Rationnel::operator/=(const Rationnel& right) {
    Uint num_temp = right.denominateur;
    Uint denom_temp = right.numerateur;
    bool neg_temp = right.negatif;

    numerateur *= num_temp;
    denominateur *= denom_temp;

    // gestion du signe
    if (negatif && right.negatif) {
        negatif = false;
    } else if (right.negatif) {
        negatif = true;
    }

    pgdc();
    return *this;
}

Rationnel operator+(Rationnel left, const Rationnel& right) { return left += right; }
Rationnel operator-(Rationnel left, const Rationnel& right) { return left -= right; }
Rationnel operator*(Rationnel left, const Rationnel& right) { return left *= right; }
Rationnel operator/(Rationnel left, const Rationnel& right) { return left /= right; }

Rationnel Rationnel::operator-() {
    negatif = !(negatif);
    return *this;
}

/* opérateurs d'incrémentation */
Rationnel &Rationnel::operator++() {
    Rationnel temp(1, 1);
    *this += temp;
    return *this;
}
Rationnel Rationnel::operator++(int) {
    Rationnel temp = *this;
    ++temp;
    return temp;
}
Rationnel &Rationnel::operator--() {
    Rationnel temp(1, 1);
    *this -= temp;
    return *this;
}
Rationnel Rationnel::operator--(int) {
    Rationnel temp = *this;
    --temp;
    return temp;
}

/* opérateurs booléens */
bool operator<(const Rationnel& left, const Rationnel& right) {
    Uint num1 = left.numerateur;
    Uint num2 = right.numerateur;
    Uint denum1 = left.denominateur;
    Uint denum2 = right.denominateur;

    return num1 * denum2 < num2 * denum1;
}
bool operator>(const Rationnel& left, const Rationnel& right) {
    Uint num1 = left.numerateur;
    Uint num2 = right.numerateur;
    Uint denum1 = left.denominateur;
    Uint denum2 = right.denominateur;

    return num2 * denum1 < num1 * denum2;
}
bool operator<=(const Rationnel& left, const Rationnel& right) {
    Uint num1 = left.numerateur;
    Uint num2 = right.numerateur;
    Uint denum1 = left.denominateur;
    Uint denum2 = right.denominateur;

    return !(num2 * denum1 < num1 * denum2);
}
bool operator>=(const Rationnel& left, const Rationnel& right) {
    Uint num1 = left.numerateur;
    Uint num2 = right.numerateur;
    Uint denum1 = left.denominateur;
    Uint denum2 = right.denominateur;

    return !(num1 * denum2 < num2 * denum1);
}
bool operator==(const Rationnel& left, const Rationnel& right) {
    return  left.numerateur == right.numerateur 
            && left.denominateur == right.denominateur 
            && left.negatif == right.negatif;
}
bool operator!=(const Rationnel& left, const Rationnel& right) {
    return  !(left.numerateur == right.numerateur 
            && left.denominateur == right.denominateur 
            && left.negatif == right.negatif);
}

/* opérateurs de lecture/écriture */
std::ostream& operator<<(std::ostream& os, const Rationnel& val) {
    if (val.negatif) {
        os << '-';
    }
    os << val.numerateur << '/' << val.denominateur;
    return os;
}
std::istream& operator>>(std::istream& is, Rationnel& val) {
    is >> val.numerateur >> val.denominateur >> val.negatif;
    val.pgdc();
    return is;
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