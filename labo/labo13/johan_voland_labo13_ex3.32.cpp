/*
    file : johan_voland_labo13_ex3.32.cpp
    brief : trouver l'approximation de pi grâce à une simulation basée sur la méthode de Monte-Carlo
    author : Johan Voland
    date : 19.10.2021
*/

#include <iostream>
#include <random>
#include <functional>
#include <iomanip>

using namespace std;

const int nbre_flechettes = pow(10, 6);

int main() {
    // génération coordonnées
    auto ximpact = bind(uniform_real_distribution<double>(-1.0, 1.0), mt19937(1));
    auto yimpact = bind(uniform_real_distribution<double>(-1.0, 1.0), mt19937(2));

    double touche;
    for (int i = 0; i < nbre_flechettes; ++i){  // on génère un nombre important de fléchettes
        if (pow(ximpact(), 2) + pow(yimpact(), 2) <= 1 && pow(ximpact(), 2) + pow(yimpact(), 2) >= -1) { // test pour voir si elles sont dans le cercle
            touche++;
        }
    }

    // calcul et affichage de pi
    double pi = (touche / nbre_flechettes) * 4;
    cout << fixed << setprecision(2) << "PI = " << pi;
}