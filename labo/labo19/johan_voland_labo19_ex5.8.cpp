/*
    file : johan_voland_labo19_ex5.8.cpp
    brief : Écrire une fonction qui décale à droite les valeurs d'un tableau. Cette dernière doit être testée.
    author : Johan Voland
    date : 12.11.2021
*/

#include <iostream>

using namespace std;

/**
 * @brief afficher le contenu d'un tableau
 * 
 * @param tbl tableau à afficher
 * @param taille_tbl nombre d'éléments du tableau
 */
void afficher_tableau(const int tbl[], size_t taille_tbl) {
    cout << "[";

    for (size_t i = 0; i < taille_tbl; ++i) {
        cout << tbl[i];
        if (i != taille_tbl - 1) {  // si ce n'est pas la dernière case du tableau
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

/**
 * @brief décaler à droite les valeurs d'un tableau
 * 
 * @param tbl tableau à modifier
 * @param taille_tbl nombre d'éléments du tableau
 */
void decalage_a_droite(int tbl[], size_t taille_tbl) {
    if (taille_tbl > 1) {
        int tmp = tbl[taille_tbl - 1];

        for (size_t i = taille_tbl - 1; i > 0; --i){    // parcourir chaque élément du tableau en partant du dernier élément jusqu'au premier
            tbl[i] = tbl[i - 1];    // remplacer la valeur actuelle avec la précédente
        }

        tbl[0] = tmp; // pour remplacer la première valeur avec la dernière
    }
}

int main() {
    int tbl[] = {1, 2, 3, 4, 5, 7, 9, 10};
    size_t taille_tbl = sizeof tbl / sizeof (int);  // calcul du nombre d'éléments du tableau

    afficher_tableau(tbl, taille_tbl);
    decalage_a_droite(tbl, taille_tbl);
    afficher_tableau(tbl, taille_tbl);
}