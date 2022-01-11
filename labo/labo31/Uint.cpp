#include "Uint.hpp"
#include <string>

using namespace std;

/* Constructeurs. */
Uint::Uint(string valeur) {
    txt = valeur;
    val = stoull(txt);
}
Uint::Uint(uint64_t valeur) {
    val = valeur;
}

/* Opérateurs arithmétiques. */
Uint Uint::operator+=(const Uint& right) {
    val += right.val;
    return *this;
}

Uint Uint::operator-=(const Uint& right) {
    val -= right.val;
    return *this;
}

Uint Uint::operator*=(const Uint& right) {
    val *= right.val;
    return *this;
}

Uint Uint::operator/=(const Uint& right) {
    val /= right.val;
    return *this;
}

/****** Opérateurs spéciaux ******/
Uint Uint::division_entiere(Uint diviseur) {
    Uint puissance2 = 1;
    Uint b = diviseur;
    while (b <= *this) {
        puissance2 *= 2;
        b *= 2;
    }

    Uint quotient = 0;
    Uint reste = *this;

    while (reste >= diviseur) {
        b /= 2;
        puissance2 /= 2;
        if (reste >= b) {
            quotient += puissance2;
            reste -= b;
        }
    }
    return quotient;
}

Uint Uint::reste(Uint diviseur) {
    Uint puissance2 = 1;
    Uint b = diviseur;
    while (b <= *this) {
        puissance2 *= 2;
        b *= 2;
    }

    Uint quotient = 0;
    Uint reste = *this;

    while (reste >= diviseur) {
        b /= 2;
        puissance2 /= 2;
        if (reste >= b) {
            quotient += puissance2;
            reste -= b;
        }
    }
    return reste;
}

Uint expModulaire (Uint base, Uint exponentiel, Uint modulo){
    Uint result = 1;
    while (exponentiel > 0) {
        if (exponentiel % 2 == 0) {
            base = (base*base) % modulo;
            exponentiel /= 2;
        } else {
            result = result * base % modulo;
            exponentiel -= 1;
        }
    }
    return result;
}