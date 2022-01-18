#ifndef SINT_HPP
#define SINT_HPP

//#include <iostream>
#include "Uint.hpp"

#include <string>
using std::string;

class Sint {
private :
    Uint val;
    bool negatif{};

    void gerer_signe(const bool &val);
    void gerer_zero();
public :
    /* constructeurs */
    Sint();
    Sint(const int64_t &val);
    Sint(const string &val);
    Sint(const Uint &val);
    Sint(const Sint &val); 

    /* opérateurs arithmétiques */
    Sint &operator=(const Sint &right);
    Sint &operator=(const string &right);
    Sint &operator-();
    Sint &operator++();
    Sint operator++(int);
    Sint &operator--();
    Sint operator--(int);
    Sint &operator+=(const Sint &right);
    Sint &operator-=(const Sint &right);
    Sint &operator*=(const Sint &right);
    Sint &operator/=(const Sint &right);
    Sint &operator%=(const Sint &right);
    friend Sint operator+(Sint left, const Sint &right);
    friend Sint operator-(Sint left, const Sint &right);
    friend Sint operator*(Sint left, const Sint &right);
    friend Sint operator/(Sint left, const Sint &right);
    friend Sint operator%(Sint left, const Sint &right);
   
    /* opérateurs logiques */
    friend bool operator<(const Sint& left, const Sint& right) {return left.val < right.val;}
    friend bool operator>(const Sint& left, const Sint& right) {return right.val < left.val;}
    friend bool operator<=(const Sint& left, const Sint& right) {return !(right.val < left.val);}
    friend bool operator>=(const Sint& left, const Sint& right) {return !(left.val < right.val);}
    friend bool operator==(const Sint& left, const Sint& right) { return left.val == right.val;}
    friend bool operator!=(const Sint& left, const Sint& right) {return !(left.val == right.val);}

    /* opérateurs de lecture/écriture */
    friend std::ostream& operator<<(std::ostream& os, const Sint& variable) {
        os << variable.val;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Sint& variable) {
        is >> variable.val;
        return is;
    }

    /* conversions */
    explicit operator int64_t() const;
    explicit operator Uint() const;

    string str() const;
};

#endif