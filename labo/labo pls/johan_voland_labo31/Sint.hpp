#ifndef LABS_AMANGOLD_SINT_HPP
#define LABS_AMANGOLD_SINT_HPP

#include "Uint.hpp"

#include <string>

using std::string;

class Sint {
 private :
    Uint nombre;
    bool negatif{};

    /* fonctions utiles */
    int compare(const Sint &val) const;
    void gestion_signe(const bool &val);
    void gestion_zero();

  public:
    /* constructeurs */
    Sint();
    Sint(const int64_t &val);
    Sint(const string &val);
    Sint(const Uint &val);
    Sint(const Sint &val);

    /* opérateurs d'assignement */
    Sint &operator=(const Sint &right);
    Sint &operator=(const string &right);
    Sint &operator-();

    /* opérateurs d'incrémentation */
    Sint &operator++();
    Sint operator++(int);
    Sint &operator--();
    Sint operator--(int);

    /* opérateurs arithmétiques */
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

    /* opérateurs d'égalité */
    friend bool operator==(const Sint &left, const Sint &right);
    friend bool operator!=(const Sint &left, const Sint &right);
    friend bool operator>(const Sint &left, const Sint &right);
    friend bool operator>=(const Sint &left, const Sint &right);
    friend bool operator<(const Sint &left, const Sint &right);
    friend bool operator<=(const Sint &left, const Sint &right);
    friend std::ostream &operator<<(std::ostream &os, const Sint &val);

    /* opérateurs de lecture/écriture */
    friend std::istream &operator>>(std::istream &is, Sint &val);
    explicit operator int64_t() const;

    /* conversions */
    explicit operator Uint() const;
    string str() const;

    // indique la taille d'un objet
    size_t size() const;
};
#endif