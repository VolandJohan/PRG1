#include "Rationnel.hpp"
#include <sstream>
#include <iostream>
#include <exception>

using Uint = uintmax_t;

/* fonctions gérant les erreurs */
/**
 * @brief Vérifie que le dénominateur n'est pas égal à 0
 * 
 */
void Rationnel::tester_denominateur() {
    try {
        if (denominateur == 0) {
            throw std::logic_error("Le denominateur ne peut pas etre 0.");
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        abort();
    }
}

/* constructeurs */
/**
 * @brief Construit un nouveau rationnel. Version où rien n'est entré.
 * 
 */
Rationnel::Rationnel() {
    negatif = false;
    numerateur = Uint(0);
    denominateur = Uint(1);
}
/**
 * @brief Construit un nouveau rationnel. Version où juste un nombre est entré.
 * 
 * @param num : juste le numérateur est entré
 */
Rationnel::Rationnel(const Uint &num) {
    negatif = false;
    numerateur = num;
    denominateur = Uint(1);
}
/**
 * @brief Construit un nouveau rationnel. Version avec le numérateur et dénominateur entrés.
 * 
 * @param num : numérateur entré
 * @param denom : dénominateur entré
 */
Rationnel::Rationnel(const Uint &num, const Uint &denom) {
    negatif = false;
    numerateur = num;
    denominateur = denom;

    tester_denominateur();
    pgdc();
}
/**
 * @brief Construit un nouveau rationnel. Version avec les 3 paramètres entrés.
 * 
 * @param num : numérateur entré
 * @param denom : dénominateur entré
 * @param neg : le signe est indiqué
 */
Rationnel::Rationnel(const Uint &num, const Uint &denom, const bool &neg) {
    negatif = neg;
    numerateur = num;
    denominateur = denom;

    tester_denominateur();
    pgdc();
}

/* opérateurs arithmétiques */
/**
 * @brief Opérateur permettant d'additionner un rationnel
 * 
 * @param right : valeur à addionner avec le rationnel
 * @return Rationnel : résultat du calcul
 */
Rationnel Rationnel::operator+=(const Rationnel& right) {
    Uint num_temp = right.numerateur;
    Uint denom_temp = right.denominateur;
    bool neg_temp = right.negatif;

    /* test que les dénominateurs sont égaux */
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
        } else {    // si numerateur > num_temp
            numerateur -= num_temp;
        }
    } else { // si les signes sont identiques, on fait une simple addition
        numerateur += num_temp;
    }

    pgdc();
    return *this;
}

/**
 * @brief Opérateur permettant de soustraire un rationnel
 * 
 * @param right : Valeur à soustraire avec le rationnel
 * @return Rationnel : Résultat du calcul
 */
Rationnel Rationnel::operator-=( const Rationnel& right) {
    Uint num_temp = right.numerateur;
    Uint denom_temp = right.denominateur;
    bool neg_temp = right.negatif;
    
    /* test que les dénominateurs sont égaux */
    if (denominateur != denom_temp) {
        // multiplier les numérateurs avec les dénominateurs
        numerateur *= denom_temp;
        num_temp *= denominateur;
        // multiplier les dénominateurs entre eux
        denominateur *= denom_temp;
    }

    /* calculs en fonction de quel nombre est supérieur et le signe */
    if (numerateur > num_temp) {
        if ((negatif == false && neg_temp == false) || (negatif == true && neg_temp == true)) {
            numerateur -= num_temp;
        } else {
            numerateur += num_temp;
        }
    } else if (numerateur < num_temp) {
        if ((negatif == false && neg_temp == false) || (negatif == true && neg_temp == true)) {
            numerateur = num_temp - numerateur;
            negatif = !(negatif);
        } else {
            numerateur += num_temp;
        }
    } else {    // si les numérateurs sont égaux
        negatif = false;
        numerateur = 0;
        denominateur = 1;
    }

    pgdc();
    return *this;
}

/**
 * @brief Opérateur permettant de multiplier un rationnel
 * 
 * @param right : valeur à multiplier par le rationnel
 * @return Rationnel : résultat du calcul
 */
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

/**
 * @brief Opérateur permettant de diviser un rationnel
 * 
 * @param right : valeur à diviser par le rationnel
 * @return Rationnel : résultat du calcul
 */
Rationnel Rationnel::operator/=(const Rationnel& right) {
    Uint num_temp = right.denominateur;
    Uint denom_temp = right.numerateur;

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

/**
 * @brief Opérateur permettant d'effectuer -rationnel
 * 
 * @return Rationnel : résultat
 */
Rationnel Rationnel::operator-() {
    negatif = !(negatif);
    return *this;
}

/* opérateurs d'incrémentation */
/**
 * @brief Opérateur ++ préfixe
 * 
 * @return Rationnel& : résultat du calcul
 */
Rationnel &Rationnel::operator++() {
    Rationnel temp(1, 1);
    *this += temp;
    return *this;
}
/**
 * @brief Opérateur ++ postfixe
 * 
 * @return Rationnel : résultat du calcul
 */
Rationnel Rationnel::operator++(int) {
    Rationnel temp = *this;
    ++temp;
    return temp;
}
/**
 * @brief Opérateur -- préfixe
 * 
 * @return Rationnel& : résultat du calcul
 */
Rationnel &Rationnel::operator--() {
    Rationnel temp(1, 1);
    *this -= temp;
    return *this;
}
/**
 * @brief Opérateur -- postfixe
 * 
 * @return Rationnel : résultat du calcul
 */
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
/**
 * @brief Opérateur permettant de lire un rationnel
 * 
 * @param os : variable pour la lecture
 * @param val : rationnel à lire
 * @return std::ostream& : résultat de la lecture
 */
std::ostream& operator<<(std::ostream& os, const Rationnel& val) {
    if (val.negatif) {
        os << '-';
    }
    os << val.numerateur << '/' << val.denominateur;
    return os;
}
/**
 * @brief Opérateur permettant d'écrire un rationnel
 * 
 * @param is : variable pour la l'écriture
 * @param val : rationnel à écrire
 * @return std::istream& : résultat de l'écriture
 */
std::istream& operator>>(std::istream& is, Rationnel& val) {
    std::cout << "Pour entrer un rationnel, suivez ce format : [numerateur] [denominateur] [true/1 = nbre negatif, false/0 = nbre positif]" << std::endl;
    is >> val.numerateur >> val.denominateur >> val.negatif;

    /* gestion des erreurs */
    try {
        if (val.denominateur == 0) {
            throw std::logic_error("Le denominateur ne peut pas etre 0.");
        }
        if (!(is)) {    // si on entre autre chose qu'un nombre (booléen pour le signe)
            throw std::invalid_argument("Il faut entrer un caractere valide.");
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        abort();
    }

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