#include <cstdint>
#include <string>

using Uint = uintmax_t;

class Rationnel {
   bool negatif;
   Uint numerateur;
   Uint denominateur;

   void pgdc();

   /* gestion des erreurs */   
   void tester_denominateur ();
 public :
    /* constructeurs */
    Rationnel();
    Rationnel(const Uint &num);
    Rationnel(const Uint &num, const Uint &denom);
    Rationnel(const Uint &num, const Uint &denom, const bool &neg);

    /* opérateurs arithmétiques */
    Rationnel operator+=(const Rationnel& right);
    Rationnel operator-=(const Rationnel& right);    
    Rationnel operator*=(const Rationnel& right);
    Rationnel operator/=(const Rationnel& right);
    friend Rationnel operator+(Rationnel left, const Rationnel& right);
    friend Rationnel operator-(Rationnel left, const Rationnel& right);
    friend Rationnel operator*(Rationnel left, const Rationnel& right);
    friend Rationnel operator/(Rationnel left, const Rationnel& right);
    Rationnel operator-();

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

    /* opérateurs de lecture/écriture */
    friend std::ostream& operator<<(std::ostream& os, const Rationnel& val);
    friend std::istream& operator>>(std::istream& is, Rationnel& val);
};