/**
 * @file exercice3.cpp
 * @author Johan Voland
 * @brief Implantation de fonctions génériques
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <array>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
void afficher(const string& txt, const T& a){
    cout < txt << "| ";
    for (size_t i = 0; i < a.size(); ++i) {
        cout << " " << a[i] << " |";
    }
    cout << endl;
}

template <typename Z, typename T, typename U>
void appondre(T a, U b) {
    size_t taille_c = a.size() + b.size();
    array<T, taille_c> c;
    for (size_t i = 0; i < a.size(); ++i) {
        c[i] = (Z)a[i];
    }
    for (size_t j = 0; j < b.size(); ++j) {
        c[a.size() + j] = (Z)b[j];
    }
    return c;
}

int main() {
    cout << fixed << setprecision (1);
    array <int, 5> a{{1,2,3,4,5}};
    afficher("a = ", a);

    array <double, 3> b{{0,10.3,20.6}};
    afficher("b = ", b);

    auto c = appondre <short> (a, b);
    afficher("c = ", c);

    auto d = appondre <double> (a, c);
    afficher("d = ", d);

    auto e = appondre <bool> (a, b);
    afficher("e = ", e);

    array <bool, 0> f{};
    afficher("f = ", f);
}