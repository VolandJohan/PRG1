/*
    file :      johan_voland_labo18.cpp
    brief :     Écrire une fonction qui retourne le sinus de son paramètre selon la série de Maclaurin.
    author :    Johan Voland
    date :      09.11.2021
*/

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

const double NOMBRE_A_CALCULER = 1;
const int NOMBRE_DE_CALCULS = 10000000;

/**
 * @brief Calcul du sinus d'un nombre selon le développement en série de Maclaurin.
 * 
 * @param nombre Nombre entrée par l'utilisateur.
 * @return Le résultat du calcul.
 */
double serie_maclaurin(double nombre) {
    double resultat = 1;
    double z = -(nombre * nombre);

    for (int i = 10; i >= 1; --i) {
        double equation = z / ((2 * i + 1) * 2 * i);
        resultat *= equation;
        resultat ++;
    }

    resultat *= nombre;

    return resultat;
}

int main() {
    cout << "Sin(" << NOMBRE_A_CALCULER << ") selon serie de MacLaurin : " << serie_maclaurin(NOMBRE_A_CALCULER) << endl;
    cout << "Sin(" << NOMBRE_A_CALCULER << ") selon la librairie cmath : " << sin(NOMBRE_A_CALCULER) << endl;

    // calcul du temps de calcul de la série de MacLaurin
    clock_t debut_maclaurin = clock();
    for (int i = 0; i < NOMBRE_DE_CALCULS; ++i) {
        serie_maclaurin(NOMBRE_A_CALCULER);
    }

    // calcul du temps de calcul de la librairie cmath
    clock_t debut_cmath = clock();
    for (int i = 0; i < NOMBRE_DE_CALCULS; ++i) {
        sin(NOMBRE_A_CALCULER);
    }

    cout << "Il faut " << (clock() - debut_maclaurin) / CLOCKS_PER_SEC << " seconde(s) pour effectuer la serie de MacLaurin." << endl;
    cout << "Il faut " << (clock() - debut_cmath) / CLOCKS_PER_SEC << " seconde(s) pour effectuer le sinus de cmath." << endl;
}