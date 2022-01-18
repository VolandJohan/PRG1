#include "Sint.hpp"
#include <cmath>
#include <sstream>
#include <stdexcept>

/* constructeurs */
Sint::Sint() {
    negatif = false;
    val = Uint();
}
Sint::Sint(const int64_t &val) { *this = Sint(std::to_string(val)); }
Sint::Sint(const string &val) { *this = val; }
Sint::Sint(const Uint &val) { *this = val; }
Sint::Sint(const Sint &val) { *this = val; }

/* opérateurs d'assignement */
Sint &Sint::operator=(const Sint &right) = default;
Sint &Sint::operator=(const string &right) {
    if (right[0] == '-') {
        negatif = true;
        val = Uint(right.substr(1, right.size() - 1));
    } else {
        val = Uint(right);
        negatif = false;
    }

    return *this;
}

// opérateur unaire
Sint &Sint::operator-() {
    negatif = !negatif;
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
        val += right.val;
    } else if (val <= right.val) {
        val = right.val - val;
        negatif = right.negatif;
    } else if (val > right.val) {
        val = val - right.val;
    }

    gerer_zero();
    return *this;
}

Sint &Sint::operator-=(const Sint &right) {
    Sint temp = right;
    *this += -temp;
    return *this;
}

Sint &Sint::operator*=(const Sint &right) {
    gerer_signe(right.negatif);
    val *= right.val;

    gerer_zero();
    return *this;
}

Sint &Sint::operator/=(const Sint &right) {
    gerer_signe(right.negatif);
    val /= right.val;

    gerer_zero();
    return *this;
}

Sint &Sint::operator%=(const Sint &right) {
    val.reste(right.val);
    return *this;
}

Sint operator+(Sint left, const Sint &right) { return left += right; }
Sint operator-(Sint left, const Sint &right) { return left -= right; }
Sint operator*(Sint left, const Sint &right) { return left *= right; }
Sint operator/(Sint left, const Sint &right) { return left /= right; }
Sint operator%(Sint left, const Sint &right) { return left %= right; }

/* conversions */
Sint::operator int64_t() const {
    int64_t val;
    std::istringstream iss(str());
    iss >> val;
    return val;
}

Sint::operator Uint() const {
    Uint val;
    std::stringstream iss(str());
    iss >> val;
    return val;
}

/* méthodes */
string Sint::str() const {
    std::stringstream buffer;

    if (negatif) {
        buffer << '-';
    }
    buffer << val;

    return buffer.str();
}

/* méthodes utiles */
void Sint::gerer_signe(const bool &val) {
    if (negatif != val) {
        negatif = true;
    } else {
        negatif = false;
    }
}

void Sint::gerer_zero() {
    if (val == 0) {
        negatif = false;
    }
}