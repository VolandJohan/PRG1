#include "Uint.hpp"
#include <cctype>
#include <cmath>
#include <functional>
#include <random>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <iostream>


/* constructeurs */
Uint::Uint() { *this = "0"; }
Uint::Uint(const uint64_t &val) { *this = val; }
Uint::Uint(const string &val) { *this = val; }
Uint::Uint(const Uint &val) { *this = val; }
Uint::Uint(const Nombre &val) { nombre = val; }

/* opérateurs d'assignement */
Uint &Uint::operator=(const Uint &right) {
    this->nombre = right.nombre;
    return *this;
}
Uint &Uint::operator=(const Uint::Digit &right) {
    *this = std::to_string(right);
    return *this;
}
Uint &Uint::operator=(const string &right) {
    nombre.clear();
    nombre.reserve(right.size());

    // inverse les entrées
    std::for_each(right.crbegin(), right.crend(), [this](char const &c) {
        if (!isdigit(c)) {
            std::cout << "Erreur !";
            exit;
        } else {
            nombre.push_back(static_cast<Digit>(c - '0'));
        }
    });

    return *this;
}

/* opérateurs d'incrémentation */
Uint &Uint::operator++() {
    *this += 1;
    return *this;
}
Uint Uint::operator++(int) {
    Uint temp = *this;
    ++temp;
    return temp;
}
Uint &Uint::operator--() {
    *this -= 1;
    return *this;
}
Uint Uint::operator--(int) {
    Uint temp = *this;
    --temp;
    return temp;
}

/* opérateurs arithmétiques */
Uint &Uint::operator+=(const Uint &right) {
    if (right.size() > std::numeric_limits<size_t>::max() - 1) {
        std::cout << "Resultat de l'addition trop eleve.";
        exit;
    } else if (right == 0) {
        return *this;
    } else if (*this == 0) {
        *this = right;
        return *this;
    }

    // Vérification de la taille et la modifie le cas échéant
    if (nombre.size() <= right.nombre.size()) {
        auto length = std::max(this->size(), right.size()) + 1;
        nombre.resize(length);
    }

    bool carry = false;
    bool carry_temp;      // carry temporaire
    auto i = nombre.begin();
    for (auto j = right.nombre.cbegin(); j != right.nombre.cend(); ++i, ++j) {
        carry_temp = (*i + *j + carry) / DIZAINE;
        *i = (*i + *j + carry) % DIZAINE;
        carry = carry_temp;
    }

    while (carry) {
        if (i == nombre.end()) {
            nombre.push_back(carry);
            break;
        }
        carry_temp = (*i + carry) / DIZAINE;
        *i = (*i + carry) % DIZAINE;
        carry = carry_temp;
        ++i;
    }

    while (nombre.back() == 0)
        nombre.pop_back();
    return *this;
}

Uint &Uint::operator-=(const Uint &right) {
    if (right.size() > this->size()) {
        std::cout << "Le resultat de la soustraction est negatif.";
        exit;
    } else if (*this == right) {
        *this = 0;
        return *this;
    }

    int carry = 0;
    int carry_temp;
    auto i = nombre.begin();
    auto j = right.nombre.cbegin();
    for (; i != nombre.end() && j != right.nombre.cend(); ++i, ++j) {
        carry_temp = (*i - *j + static_cast<Digit>(carry)) / DIZAINE <= (*i | *j) ? 0 : -1;
        *i = (*i - *j + static_cast<Digit>(1 + carry) + (DIZAINE - 1)) % DIZAINE;
        carry = carry_temp;
    }

    if (carry < 0)
        nombre.back()--;

    while (nombre.back() == 0)
        nombre.pop_back();
    return *this;
}

Uint &Uint::operator*=(const Uint &right) {
    if (*this == 0 || right == 0) {
        *this = 0;
        return *this;
    } else if (std::max(this->size(), right.size()) == 1 &&
               this->nombre.front() * right.nombre.front() < DIZAINE) {
        *this = this->nombre.front() * right.nombre.front();
        return *this;
    }

    Nombre ans;
    ans.resize(this->size() + right.size());

    size_t j = 0;
    for (; j < right.size(); ++j) {
        // dans le cas où le digit à droite est à 0
        if (right.nombre.at(j) == 0) {
            ans[j + this->size()] = 0;
            continue;
        }

        size_t i = 0;
        Digit k = 0;
        for (; i < nombre.size(); ++i) {
            Digit temp = this->nombre[i] * right.nombre[j] + ans[i + j] + k;
            ans[i + j] = temp % DIZAINE;
            k = temp / DIZAINE;
        }
        ans[i + j] = k;
    }

    nombre = Nombre(ans);

    while (nombre.back() == 0)
        nombre.pop_back();
    return *this;
}

Uint &Uint::operator/=(const Uint &right) {
    if (right == 0) {
        std::cout << "On ne peut pas diviser par 0.";
        exit;
    } else if (*this < right or *this == 0) {
        *this = 0;
        return *this;
    } else if (*this == right) {
        *this = 1;
        return *this;
    } else if (right.size() == 1) {
        this->division_courte(right.nombre[0]);
        return *this;
    }

    *this = this->division_longue(right);
    return *this;
}

Uint &Uint::operator%=(const Uint &right) {
    if (right == 0) {
        std::cout << "On ne peut pas diviser par 0.";
        exit;
    } else if (*this < right) {
        return *this;
    } else if (*this == right) {
        *this = 0;
        return *this;
    }

    *this = this->reste(right);
    return *this;
}

Uint operator+(Uint left, const Uint &right) { return left += right; }
Uint operator-(Uint left, const Uint &right) { return left -= right; }
Uint operator*(Uint left, const Uint &right) { return left *= right; }
Uint operator/(Uint left, const Uint &right) { return left /= right; }
Uint operator%(Uint left, const Uint &right) { return left %= right; }

/* opérateurs de comparaison */
bool operator==(const Uint &left, const Uint &right) {
    return left.comparer(right) == 0;
}
bool operator!=(const Uint &left, const Uint &right) {
    return left.comparer(right) != 0;
}
bool operator>(const Uint &left, const Uint &right) {
    return left.comparer(right) == 1;
}
bool operator>=(const Uint &left, const Uint &right) {
    return left.comparer(right) >= 0;
}
bool operator<(const Uint &left, const Uint &right) {
    return left.comparer(right) == -1;
}
bool operator<=(const Uint &left, const Uint &right) {
    return left.comparer(right) <= 0;
}

/* opérateurs de lecture/ériture */
std::ostream &operator<<(std::ostream &os, const Uint &val) {
    os << val.str();
    return os;
}

std::istream &operator>>(std::istream &is, Uint &val) {
    std::string temp;
    if (is >> temp)
        val = Uint(temp);
    else
        is.clear(std::ios::badbit | is.rdstate());

    return is;
}

/* conversions */
Uint::operator uint64_t() const {
    if (*this > std::numeric_limits<uint64_t>::max()) {
        std::cout << "Le nombre est trop grand pour être converti en uint64_t.";
        exit;
    }

    uint64_t val;
    std::istringstream iss(str());
    iss >> val;
    return val;
}
string Uint::str() const {
    std::stringstream buffer;

    std::for_each(nombre.crbegin(), nombre.crend(), [&buffer](Digit const &d) { buffer << d; });

    return buffer.str();
}

size_t Uint::size() const { return nombre.size(); }

/* fonctions utiles */

/**
 * @brief produit un nombre aléatoire
 * 
 * @param size Indique la valeur maximum pouvant être générée
 */
void Uint::randomize(const size_t &size) {
    static std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint64_t> digitDist(0, 9);
    std::uniform_int_distribution<uint64_t> nonzeroDist(1, 9);

    nombre.resize(size);

    std::generate(nombre.begin(), nombre.end() - 1, [&gen, &digitDist]() { return digitDist(gen); });

    nombre.back() = nonzeroDist(gen);
}

int Uint::comparer(const Uint &val) const {
    if (this->size() < val.size())
        return -1;
    else if (this->size() > val.size())
        return 1;
    else {
        auto it1 = this->nombre.crbegin();
        auto it2 = val.nombre.crbegin();
        for (; it1 != nombre.crend() && it2 != val.nombre.crend(); ++it1, ++it2)
            if (*it1 < *it2)
                return -1;
            else if (*it1 > *it2)
                return 1;
        return 0;
    }
}

/**
 * @brief divise un Uint avec une valeur de 1 digit
 * 
 * @param diviseur Valeur divisant le Uint
 */
void Uint::division_courte(const Digit &diviseur) {
    if (diviseur == 0)
        return;

    for (size_t i = nombre.size() - 1; i > 0; i--) {
        nombre[i - 1] += (nombre[i] % diviseur) * DIZAINE;
        nombre[i] /= diviseur;
    }

    nombre[0] /= diviseur;
    while (nombre.back() == 0)
        nombre.pop_back();
}

/**
 * @brief divise un Uint avec un autre Uint
 * 
 * @param diviseur Valeur divisant le Uint
 * @return std::pair<Uint, Uint> retourne soit le résultat de la division entière ou soit le reste
 */
Uint Uint::division_longue(const Uint &diviseur) {
    Uint puissance_de_2 = 1;
    Uint b = diviseur;
    Uint quotient = 0;
    Uint reste = *this;

    while (b <= *this) {
        puissance_de_2 *= 2;
        b *= 2;
    }

    while (reste >= diviseur) {
        b.division_courte(2);
        puissance_de_2.division_courte(2);

        if (reste >= b) {
            quotient += puissance_de_2;
            reste -= b;
        }
    }

    return quotient;
}

/**
 * @brief calcul le reste d'un Uint avec un autre
 * 
 * @param diviseur Uint divisant le nombre
 * @return Uint Reste de la division
 */
Uint Uint::reste(const Uint &diviseur) {
    Uint puissance_de_2 = 1;
    Uint b = diviseur;
    Uint quotient = 0;
    Uint reste = *this;

    while (b <= *this) {
        puissance_de_2 *= 2;
        b *= 2;
    }

    while (reste >= diviseur) {
        b.division_courte(2);
        puissance_de_2.division_courte(2);

        if (reste >= b) {
            quotient += puissance_de_2;
            reste -= b;
        }
    }

    return reste;
}

/**
 * @brief calcul l'exponentielle modulaire, basé sur le labo16
 * 
 * @param base 
 * @param exp 
 * @param mod 
 * @return Uint 
 */
Uint mod_pow(Uint base, Uint exp, const Uint &mod) {
    Uint ans = 1;

    while (exp > 0) {
        if (exp % 2 == 0) {
            base = base * base % mod;
            exp /= 2;
        } else {
            ans = ans * base % mod;
            exp -= 1;
        }
    }

    return ans;
}