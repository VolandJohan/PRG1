#ifndef UINT_HPP
#define UINT_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

class Uint {
private :
    vector<uint_fast32_t> val;

    friend class Sint;

    /* fonctions spéciales */
    void petite_division(const uint_fast32_t &diviseur);
    Uint division_entiere(const Uint &diviseur);
    Uint reste(const Uint &diviseur);
    friend Uint mod_pow(Uint base, Uint exponentiel, const Uint &modulo);
    void gerer_zeros();

public :
    /* constructeur */
    Uint();
    Uint(const string &val);
    Uint(const uint64_t &val);
    Uint(const Uint &val);
    Uint(const vector<uint_fast32_t> &val);

    Uint &operator=(const Uint &right);
    Uint &operator=(const uint_fast32_t &right);
    Uint &operator=(const string &right);

    /* opérateurs arithmétiques */
    Uint &operator+=(const Uint &right);
    Uint &operator-=(const Uint &right);
    Uint &operator*=(const Uint &right);
    Uint &operator/=(const Uint &right);
    Uint &operator%=(const Uint &right);
    friend Uint operator+(Uint left, const Uint &right) { return left += right; }
    friend Uint operator-(Uint left, const Uint &right) { return left -= right; }
    friend Uint operator*(Uint left, const Uint &right) { return left *= right; }
    friend Uint operator/(Uint left, const Uint &right) { return left /= right; }
    friend Uint operator%(Uint left, const Uint &right) { return left %= right; }

    /* opérateurs logiques */
    friend bool operator<(const Uint& left, const Uint& right) {return left.val < right.val;}
    friend bool operator>(const Uint& left, const Uint& right) {return right.val < left.val;}
    friend bool operator<=(const Uint& left, const Uint& right) {return !(right.val < left.val);}
    friend bool operator>=(const Uint& left, const Uint& right) {return !(left.val < right.val);}

    friend bool operator==(const Uint& left, const Uint& right) { return left.val == right.val;}
    friend bool operator!=(const Uint& left, const Uint& right) {return !(left.val == right.val);}

    /* opérateurs de lecture/écriture */
    friend std::ostream &operator<<(std::ostream &os, const Uint &variable) {
        os << variable.str();
        return os;
    }
    friend std::istream &operator>>(std::istream &is, Uint &variable) {
        std::string temp;
        if (is >> temp) {
            variable = Uint(temp);
        } else {
            is.clear(std::ios::badbit | is.rdstate());
        }
        return is;
    }

    /* opérateurs d'incrémentation */
    // opérateur préfixe
    Uint &operator++() {
        *this += 1;
        return *this;
    }
    // opérateur postfixe
    Uint operator++(int) {
        Uint tmp = *this;
        ++tmp;
        return tmp;
    }
    Uint &operator--() {
        *this -= 1;
        return *this;
    }
    Uint operator--(int) {
        Uint tmp = *this;
        --tmp;
        return tmp;
    }

    /* conversions */
    explicit operator uint64_t() const;

    string str() const;
    size_t size() const;
    bool nombre_premier() const;
    void randomize(const size_t &size);
};

#endif