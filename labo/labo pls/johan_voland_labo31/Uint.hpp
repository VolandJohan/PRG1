#ifndef LABS_AMANGOLD_UINT_HPP
#define LABS_AMANGOLD_UINT_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

class Uint {
 private :
    friend class Sint;

    typedef uint_fast32_t Digit;
    typedef vector<Digit> Nombre;

    // utilisé pour les opérations de base
    const Digit DIZAINE = 10;

    Nombre nombre;

    /* fonctions diverses */
    int comparer(const Uint &val) const;
    friend Uint mod_pow(Uint base, Uint exp, const Uint &mod);
    // divise la valeur par un simple digit
    void division_courte(const Digit &diviseur);
    // divise un Uint avec un autre
    Uint division_longue(const Uint &diviseur);
    // divise un Uint pour avoir le reste
    Uint reste(const Uint &diviseur);

 public:
    /* constructeurs */
    Uint();
    Uint(const uint64_t &val);
    Uint(const string &val);
    Uint(const Uint &val);
    Uint(const Nombre &val);

    /* opérateurs d'assigenment */
    Uint &operator=(const Uint &right);
    Uint &operator=(const Digit &right);
    Uint &operator=(const string &right);

    /* opérateurs d'incrémentation */
    Uint &operator++();
    Uint operator++(int);
    Uint &operator--();
    Uint operator--(int);

    /* opérateurs arithmétiques */
    Uint &operator+=(const Uint &right);
    Uint &operator-=(const Uint &right);
    Uint &operator*=(const Uint &right);
    Uint &operator/=(const Uint &right);
    Uint &operator%=(const Uint &right);
    friend Uint operator+(Uint left, const Uint &right);
    friend Uint operator-(Uint left, const Uint &right);
    friend Uint operator*(Uint left, const Uint &right);
    friend Uint operator/(Uint left, const Uint &right);
    friend Uint operator%(Uint left, const Uint &right);

    /* comparaisons */
    friend bool operator==(const Uint &left, const Uint &right);
    friend bool operator!=(const Uint &left, const Uint &right);
    friend bool operator>(const Uint &left, const Uint &right);
    friend bool operator>=(const Uint &left, const Uint &right);
    friend bool operator<(const Uint &left, const Uint &right);
    friend bool operator<=(const Uint &left, const Uint &right);

    /* opérateurs d'écriture/lecture */
    friend std::ostream &operator<<(std::ostream &os, const Uint &val);
    friend std::istream &operator>>(std::istream &is, Uint &val);

    /* conversions */
    explicit operator uint64_t() const;
    string str() const;

    /* fonctions utilses */
    // indique taille de l'objet
    size_t size() const;
    // créé une valeur aléatoire
    void randomize(const size_t &size);
};

#endif // LABS_AMANGOLD_UINT_HPP