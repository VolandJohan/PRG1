#include "Sint.hpp"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <algorithm>

/* constructeurs */
Sint::Sint() {
    negatif = false;
    nombre = Uint();
}
Sint::Sint(const int64_t &val) { *this = Sint(std::to_string(val)); }
Sint::Sint(const string &val) { *this = val; }
Sint::Sint(const Uint &val) { *this = val.str(); }
Sint::Sint(const Sint &val) { *this = val; }

/* opérateurs d'assignement */
Sint &Sint::operator=(const Sint &right) = default;

Sint &Sint::operator=(const string &right) {
    if (right[0] == '-') {
        negatif = true;
        nombre = Uint(right.substr(1, right.size() - 1));
    } else {
        nombre = Uint(right);
        negatif = false;
    }

    return *this;
}

/* opérateurs d'incrémentation */
Sint &Sint::operator++() {
    *this += 1;
    return *this;
}
Sint Sint::operator++(int) {
    Sint temp = *this;
    ++temp;
    return temp;
}
Sint &Sint::operator--() {
    *this -= 1;
    return *this;
}
Sint Sint::operator--(int) {
    Sint temp = *this;
    --temp;
    return temp;
}

/* opérateurs arithmétiques */
Sint &Sint::operator+=(const Sint &right) {
    if (negatif == right.negatif) {
        nombre += right.nombre;
    } else if (nombre <= right.nombre) {
        nombre = right.nombre - nombre;
        negatif = right.negatif;
    } else if (nombre > right.nombre) {
        nombre = nombre - right.nombre;
    }

    gestion_zero();
    return *this;
}

Sint &Sint::operator-=(const Sint &right) {
    Sint temp = right;
    *this += -temp;
    return *this;
}

Sint &Sint::operator*=(const Sint &right) {
    gestion_signe(right.negatif);
    nombre *= right.nombre;

    gestion_zero();
    return *this;
}

Sint &Sint::operator/=(const Sint &right) {
    gestion_signe(right.negatif);
    nombre /= right.nombre;

    gestion_zero();
    return *this;
}

Sint &Sint::operator%=(const Sint &right) {
    nombre %= right.nombre;
    return *this;
}

Sint operator+(Sint left, const Sint &right) { return left += right; }
Sint operator-(Sint left, const Sint &right) { return left -= right; }
Sint operator*(Sint left, const Sint &right) { return left *= right; }
Sint operator/(Sint left, const Sint &right) { return left /= right; }
Sint operator%(Sint left, const Sint &right) { return left %= right; }
Sint &Sint::operator-() {
    negatif = !negatif;
    return *this;
}

/* omprateurs de comparaison */
bool operator==(const Sint &left, const Sint &right) {
    return left.compare(right) == 0;
}
bool operator!=(const Sint &left, const Sint &right) {
    return left.compare(right) != 0;
}
bool operator>(const Sint &left, const Sint &right) {
    return left.compare(right) == 1;
}
bool operator>=(const Sint &left, const Sint &right) {
    return left.compare(right) >= 0;
}
bool operator<(const Sint &left, const Sint &right) {
    return left.compare(right) == -1;
}
bool operator<=(const Sint &left, const Sint &right) {
    return left.compare(right) <= 0;
}

/* opérateurs de lecture/écriture */
std::ostream &operator<<(std::ostream &os, const Sint &val) {
    os << val.str();
    return os;
}

std::istream &operator>>(std::istream &is, Sint &val) {
    std::string temp;
    if (is >> temp)
        val = Sint(temp);
    else
        is.clear(std::ios::badbit | is.rdstate());

    return is;
}

/* conversions */
Sint::operator int64_t() const {
    if (*this > std::numeric_limits<int64_t>::max())
        throw std::length_error("Number too big to cast to int64_t.");

    int64_t val;
    std::istringstream iss(str());
    iss >> val;
    return val;
}

Sint::operator Uint() const {
    Uint val;
    std::istringstream iss(str());
    iss >> val;
    return val;
}

/* fonctions utiles */
string Sint::str() const {
    std::stringstream buffer;

    if (negatif)
        buffer << '-';
    buffer << nombre;

    return buffer.str();
}

size_t Sint::size() const { return nombre.size(); }

int Sint::compare(const Sint &val) const {
    if (negatif && val.negatif)
        return nombre.comparer(val.nombre) * -1;
    else if (!negatif && !val.negatif)
        return nombre.comparer(val.nombre);
    else if (!negatif && val.negatif)
        return 1;
    else if (negatif && !val.negatif)
        return -1;
    else
        return 0;
}

void Sint::gestion_signe(const bool &val) {
    if (negatif != val)
        negatif = true;
    else
        negatif = false;
}

void Sint::gestion_zero() {
    if (nombre == 0)
        negatif = false;
}