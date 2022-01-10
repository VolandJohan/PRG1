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