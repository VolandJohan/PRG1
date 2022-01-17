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
    /* constructeur */
    Uint() {};
    Uint(const string valeur);
    Uint(const uint64_t valeur);
    explicit operator uint64_t() { return (uint64_t) val; };

    /* opérateurs arithmétiques */
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

    /* opérateurs logiques */
    friend bool operator<(const Uint& left, const Uint& right) {return left.val < right.val;}
    friend bool operator>(const Uint& left, const Uint& right) {return right.val < left.val;}
    friend bool operator<=(const Uint& left, const Uint& right) {return !(right.val < left.val);}
    friend bool operator>=(const Uint& left, const Uint& right) {return !(left.val < right.val);}

    friend bool operator==(const Uint& left, const Uint& right) { return left.val == right.val;}
    friend bool operator!=(const Uint& left, const Uint& right) {return !(left.val == right.val);}

    /* opérateurs de lecture/écriture */
    friend ostream& operator<<(ostream& os, const Uint& variable) {
        os << variable.val;
        return os;
    }
    friend istream& operator>>(istream& is, Uint& variable) {
        is >> variable.val;
        return is;
    }
    friend istream& operator>>(fstream& fs, Uint& variable) {
        fs >> variable.val;
        return fs;
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

    /* fonctions spéciales */
    Uint division_entiere(Uint diviseur);
    Uint reste(Uint diviseur);
};

// exponetielle modulaire
Uint mod_pow(Uint base, Uint exponentiel, Uint modulo);

#endif