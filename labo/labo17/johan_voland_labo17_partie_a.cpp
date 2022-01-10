/*
    file :      johan_voland_labo17_partie_a.cpp
    brief :     Calcul de la suite de Syracuse selon la donnée de l'exercice 4.16, partie A. Le nombre d'itérations pour parvenir
                au résultat doit être également affiché.
    author :    Johan Voland
    date :      09.11.2021
*/

#include <iostream>

using namespace std;

void suite_syracuse(int nbre) {
    int iteration = 0;

    while (nbre != 1) {
        // cas si le nombre entré est pair
        if (nbre % 2 == 0) {
            nbre /= 2;
        } else {    // si le nombre entré est impair
            nbre *= 3;
            nbre += 1;
        }

        // on augmente le nombre d'itération
        ++iteration;

        cout << nbre << " ";
    }

    cout << endl << "Il aura fallu " << iteration << " iteration pour ateindre ce resultat" << endl;
}

int main() {
    // entrée du nombre
    cout << "Entrez un nombre entier positif : ";
    int nbre;
    cin >> nbre;

    suite_syracuse(nbre);
}