#include <cstdint>  // pour le uintmax_t
#include <string>   // pour l'opérateur <<

using Uint = uintmax_t;

class Rationnel {
 private :
    bool negatif;
    Uint numerateur;
    Uint denominateur;

    void pgdc();
 public :
    /* constructeurs */
    Rationnel();
    Rationnel(Uint& num, Uint& denom);
    Rationnel(Uint& num, Uint& denom, bool& neg);

    /* opérateurs arithmétiques */
    Rationnel operator+=(Rationnel& right);
    Rationnel operator-=(Rationnel& right);    
    Rationnel operator*=(const Rationnel& right);
    Rationnel operator/=(const Rationnel& right);
    friend Rationnel operator+(Rationnel left, const Rationnel& right);
    friend Rationnel operator-(Rationnel left, const Rationnel& right);
    friend Rationnel operator*(Rationnel left, const Rationnel& right);
    friend Rationnel operator/(Rationnel left, const Rationnel& right);

    /* opérateurs d'incrémentation */
    Rationnel &operator++();
    Rationnel operator++(int);
    Rationnel &operator--();
    Rationnel operator--(int);

    /* opérateurs booléens */
    friend bool operator<(const Rationnel& left, const Rationnel& right);
    friend bool operator>(const Rationnel& left, const Rationnel& right);
    friend bool operator<=(const Rationnel& left, const Rationnel& right);
    friend bool operator>=(const Rationnel& left, const Rationnel& right);
    friend bool operator==(const Rationnel& left, const Rationnel& right);
    friend bool operator!=(const Rationnel& left, const Rationnel& right);

    // operateur de lecture
    friend std::ostream& operator<<(std::ostream& os, const Rationnel& val);
};