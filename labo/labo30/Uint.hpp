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
    Uint() {};
    Uint(const string valeur);
    Uint(const uint64_t valeur);

    /****** Opérateurs arithmétiques ******/
    Uint operator+=(const Uint& right);
    friend Uint operator+(Uint left, const Uint& right) {
        left += right;
        return left;
    }
    Uint operator*=(const Uint& right);
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

    /****** Opérateurs logiques ******/
    friend bool operator<(const Uint& left, const Uint& right) {return left.val < right.val;}
    friend bool operator>(const Uint& left, const Uint& right) {return right.val < left.val;}
    friend bool operator<=(const Uint& left, const Uint& right) {return !(right.val < left.val);}
    friend bool operator>=(const Uint& left, const Uint& right) {return !(left.val < right.val);}

    friend bool operator==(const Uint& left, const Uint& right) { return left.val == right.val;}
    friend bool operator!=(const Uint& left, const Uint& right) {return !(left.val == right.val);}

    friend ostream& operator<<(ostream& os, const Uint& variable) {
        os << variable.val;
        return os;
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

    /****** Fonctions spéciales ******/
    Uint division_entiere(Uint diviseur);
    Uint reste(Uint diviseur);
};

#endif