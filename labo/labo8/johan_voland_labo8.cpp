#include <iostream>
#include <cmath>
#include <iomanip>

/*
    file : johan_voland_labo8.cpp
    brief : calcule le volume d'une bouteille en fonction des données entrée par l'utilisateur
    author : Johan Voland
    date : 05.10.2021
*/

using namespace std;

const int CM3_PAR_DM3 = 1000;

int main() {
    // -- ENTRÉE DES DONNÉES --
    cout << "Entrez les dimensions du premier cylindre (r1 et h1) : " << endl;
    double r1, h1;
    cin >> r1 >> h1;

    cout << "Entrez les dimensions du deuxieme cylindre (r2 et h2) : " << endl;
    double r2, h2;
    cin >> r2 >> h2;

    cout << "Entrez la hauteur du cone tronque (h3) : " << endl;
    double h3;
    cin >> h3;

    // -- CALCULS --
    // pi = inverse de cos(-1)
    double pi = acos(-1);

    // calcul des volumes
    double volume_cylindre1 = pi * pow(r1, 2) * h1;
    double volume_cylindre2 = pi * pow(r2, 2) * h2;
    double volume_cone = h3 * (pi / 3) * (pow(r1, 2) + pow(r2, 2) + r1 * r2);

    double volume_total = volume_cylindre1 + volume_cylindre2 + volume_cone; // somme des volumes calulés précédement

    // conversion du volume total en DM3
    volume_total = volume_total / CM3_PAR_DM3;

    // -- AFFICHAGE --
    cout << setprecision(1) << fixed;    // pour n'afficher qu'un chiffre après la virgule
    
    cout << "Volume de la bouteille : " << volume_total << " L" << endl;
}