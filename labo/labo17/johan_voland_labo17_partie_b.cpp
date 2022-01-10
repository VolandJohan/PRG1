/*
    file :      johan_voland_labo17_partie_b.cpp
    brief :     calcul de la suite de Syracuse selon la donnée de l'exercice 4.16, partie B. Cette fois-ci, il faut afficher le nombre d'itérations
                pour n nombre entiers positifs.
    author :    Johan Voland
    date :      09.11.2021
*/

#include <iostream>

using namespace std;

void suite_syracuse(int nbre_a_calculer) {
    int iteration = 0;
    int nbre_avant_calcul = nbre_a_calculer;

    while (nbre_a_calculer != 1) {
        // cas si le nombre entré est pair
        if (nbre_a_calculer % 2 == 0) {
            nbre_a_calculer /= 2;
        } else {    // si le nombre entré est impair
            nbre_a_calculer *= 3;
            nbre_a_calculer += 1;
        }

        // on augmente le nombre d'itération
        ++iteration;
    }

    cout << endl << "Il faut " << iteration << " iteration pour effectuer la suite de Syracuse pour " << nbre_avant_calcul << endl;
}

int main() {
    // entrée du nombre
    cout << "Entrez un nombre entier positif : ";
    int nbre_inscrit;
    cin >> nbre_inscrit;

    for (int i = 1; i <= nbre_inscrit; ++i) {
        suite_syracuse(i);
    }
}