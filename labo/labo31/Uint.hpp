#ifndef UINT_HPP
#define UINT_HPP

#include <string>
#include <iostream>

using namespace std;

class Uint {
private :
    string txt;
    uint64_t val;
public :
    /* Constructeurs. */
    Uint() {};
    Uint(const string valeur);
    Uint(const uint64_t valeur);
    explicit operator uint64_t() { return (uint64_t) val; };

    /* Opérateurs arithmétiques. */
    Uint operator+=(const Uint& right);
    friend Uint operator+(Uint left, const Uint& right) {
        left += right;
        return left;
    }
    Uint operator*=(const Uint& right);
    friend Uint operator*(Uint left, const Uint& right) {
        left *= right;
        return left;
    }
    Uint operator-=(const Uint& right);
    friend Uint operator-(Uint left, const Uint& right) {
        left -= right;
        return left;
    }
    Uint operator/=(const Uint& right);
    friend Uint operator/(Uint left, const Uint& right) {
        left /= right;
        return left;
    }
    friend Uint operator%(Uint left, const Uint& right) {
        return left.reste(right);
    }

    /* Opérateurs logiques. */
    friend bool operator<(const Uint& left, const Uint& right) {return left.val < right.val;}
    friend bool operator>(const Uint& left, const Uint& right) {return right.val < left.val;}
    friend bool operator<=(const Uint& left, const Uint& right) {return !(right.val < left.val);}
    friend bool operator>=(const Uint& left, const Uint& right) {return !(left.val < right.val);}

    friend bool operator==(const Uint& left, const Uint& right) { return left.val == right.val;}
    friend bool operator!=(const Uint& left, const Uint& right) {return !(left.val == right.val);}

    /* Opérateurs de lecture/écriture */
    friend ostream& operator<<(ostream& os, const Uint& variable) {
        os << variable.val;
        return os;
    }
    friend istream& operator>>(istream& is, Uint& variable) {
        is >> variable.val;
        return is;
    }

    // opérateur préfixe
    Uint& operator++() {
        ++val;
        return *this;
    }
    // opérateur postfixe
    Uint operator++(int) {
        Uint tmp = *this;
        ++(*this);
        return tmp;
    }

    /* Fonctions spéciales */
    Uint division_entiere(Uint diviseur);
    Uint reste(Uint diviseur);
};

// exponetielle modulaire
Uint mod_pow(Uint base, Uint exponentiel, Uint modulo);

#endif