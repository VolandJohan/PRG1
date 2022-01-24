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
Uint::Uint(const vector<uint_fast32_t> &val) { *this = val; }

/* opérateurs d'affectation */
Uint &Uint::operator=(const Uint &right) {
    this->val = right.val;
    return *this;
}
Uint &Uint::operator=(const uint_fast32_t &right) {
    *this = std::to_string(right);
    return *this;
}
Uint &Uint::operator=(const string &right) {
    val.clear();
    val.reserve(right.size());

    std::for_each(right.crbegin(), right.crend(), [this](char const &c) {
        val.push_back(static_cast<uint_fast32_t>(c - '0'));
    });

    return *this;
}

/* opérateurs arithmétiques */
Uint &Uint::operator+=(const Uint &right) {
    vector<uint_fast32_t> diviseur;
    diviseur = 10;
    
    if (right == 0) {
        return *this;
    } else if (*this == 0) {
        *this = right;
        return *this;
    }

    if (val.size() <= right.val.size()) {
        auto longueur = std::max(this->size(), right.size()) + 1;
        val.resize(longueur);
    }

    bool carry = false;
    bool carry_temp;
    auto i = val.begin();
    for (auto j = right.val.cbegin(); j != right.val.cend(); ++j) {
        ++i;
        carry_temp = (*i + *j + carry) / 10;
        *i = (*i + *j + carry) % 10;
        carry = carry_temp;
    }

    while (carry) {
        if (i == val.end()) {
            val.push_back(carry);
            break;
        }
        carry_temp = (*i + carry) / 10;
        *i = (*i + carry) % 10;
        carry = carry_temp;
        ++i;
    }

    this->gerer_zeros();
    return *this;
}

Uint &Uint::operator-=(const Uint &right) {
    int carry = 0;
    int carry_temp;
    auto i = val.begin();
    auto j = right.val.cbegin();

    for(; i != val.end() && j != right.val.cend(); ++i, ++j) {
        carry_temp = (*i - *j + static_cast<uint_fast32_t>(carry)) / 10 <= (*i | *j) ? 0 : -1;
        *i = (*i - *j + static_cast<uint_fast32_t>(1 + carry) + (9)) % 10;
        carry = carry_temp;
    }

    if (carry < 0) {
        val.back()--;
    }

    this->gerer_zeros();
    return *this;
}

Uint &Uint::operator*=(const Uint &right) {
    vector<uint_fast32_t> ans;
    ans.resize(this->size() + right.size());

    size_t j = 0;
    for (; j < right.size(); ++j) {
        // Special case if the rhs digit is 0.
        if (right.val.at(j) == 0) {
            ans[j + this->size()] = 0;
            continue;
        }

        size_t i = 0;
        uint_fast32_t k = 0;
        for (; i < val.size(); ++i) {
            uint_fast32_t temp = this->val[i] * right.val[j] + ans[i + j] + k;
            ans[i + j] = temp % 10;
            k = temp / 10;
        }
        ans[i + j] = k;
    }

    val = vector<uint_fast32_t>(ans);

    this->gerer_zeros();
    return *this;
}

Uint &Uint::operator/=(const Uint &right) {
    if (right == 0) {
        throw std::domain_error("Can not divide by zero.");
    } else if (*this < right || *this == 0) {
        *this = 0;
        return *this;
    } else if (*this == right) {
        *this = 1;
        return *this;
    } else if (right.size() == 1) {
        this->petite_division(right.val[0]);
        return *this;
    }

    auto ans = division_entiere(right);
    *this = ans;
    return *this;
}

Uint &Uint::operator%=(const Uint &right) {
    if (right == 0) {
        throw std::domain_error("Can not divide by zero.");
    } else if (*this < right) {
        return *this;
    } else if (*this == right) {
        *this = 0;
        return *this;
    }

    auto ans = reste(right);
    *this = ans;
    return *this;
}

// conversion
Uint::operator uint64_t() const {
    uint64_t val;
    std::istringstream iss(str());
    iss >> val;
    return val;
}

/* méthodes */
string Uint::str() const {
    std::stringstream buffer;
    std::for_each(val.crbegin(), val.crend(), [&buffer](uint_fast32_t const &d) { buffer << d; });
    return buffer.str();
}

size_t Uint::size() const { return val.size(); }

bool Uint::nombre_premier() const {
    static std::random_device rd;
    // Maximum rotations for prime validation.
    static constexpr size_t MAX_PRIME_ROTATIONS = 10;

    if (*this < 2) {
        return false;
    } else if (*this == 2) {
        return true;
    }

    for (size_t i = 0; i < 10; i++) {
        // Generate an integer 2 <= n < prime
        auto generate =
            std::bind(std::uniform_int_distribution<size_t>(2, uint64_t(*this) - 1), std::mt19937(rd()));
        Uint a = generate();

        // Apply Fermat's Little Theorem.
        if (mod_pow(a, Uint(*this - 1), *this) != 1) {
            return false;
        }

        Uint q = 1, u = *this - 1;
        while (u % 2 == 0 && q == 1) {
            u /= 2;
            q = mod_pow(a, u, *this);

            if (q != 1 && q != *this - 1) {
                return false;
            }
        }
    }

    return true;
}

void Uint::randomize(const size_t &size) {
    static std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint64_t> digitDist(0, 9);
    std::uniform_int_distribution<uint64_t> nonzeroDist(1, 9);

    val.resize(size);

    std::generate(val.begin(), val.end() - 1,
                  [&gen, &digitDist]() { return digitDist(gen); });

    val.back() = nonzeroDist(gen);
}

void Uint::gerer_zeros() {
    while (val.back() == 0) {
        val.pop_back();
    }
}

void Uint::petite_division(const uint_fast32_t &diviseur) {
    if (diviseur == 0)
        return;

    for (size_t i = val.size() - 1; i > 0; i--) {
        val[i - 1] += (val[i] % diviseur) * 10;
        val[i] /= diviseur;
    }

    val[0] /= diviseur;
    gerer_zeros();
}

/* opérations spéciales */

/**
 * @brief Effectue la division entière du Uint avec le nombre entre parenthèses.
 * 
 * @param diviseur  valeur divisant le Uint
 * @return Uint résultat de la division entière
 */
Uint Uint::division_entiere(const Uint &diviseur) {
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

/**
 * @brief Calcul le reste du Uint avec le diviseur
 * 
 * @param diviseur 
 * @return Uint 
 */
Uint Uint::reste(const Uint &diviseur) {
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

/**
 * @brief Calcul l'exponetielle modulaire en fonction des valeurs entrées.
 * 
 * @param base 
 * @param exponentiel 
 * @param modulo 
 * @return Uint 
 */
Uint mod_pow (Uint base, Uint exponentiel, const Uint &modulo){
    Uint result = 1;

    Uint test = 10;
    Uint test2 = 3;
    test += test2;

    std::cout << "Add : " << test << std::endl;

    std::cout << "base : " << base << std::endl;
    while (exponentiel > 0) {
        if (exponentiel % 2 == 0) {
            std::cout << "Le resultat est pair" << std::endl;
            base = (base * base) % modulo;
            std::cout << "base : " << base << std::endl;
            exponentiel /= 2;
        } else {
            std::cout << "Le resultat est impair" << std::endl;
            result = (result * base) % modulo;
            std::cout << "base apres calcul : " << base << std::endl;
            exponentiel -= 1;
        }
    }
    return result;
}