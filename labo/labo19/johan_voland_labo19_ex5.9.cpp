/*
    file : johan_voland_labo19_ex5.9.cpp
    brief : Écrire une fonction qui supprime l'élément central d'un tableau. Le nombre d'éléments à supprimer varie si la valeur est paire ou impaire.
    author : Johan Voland
    date : 12.11.2021
*/

#include <iostream>

using namespace std;

/**
 * @brief afficher le contenu d'un tableau
 * 
 * @param tab tableau à afficher
 * @param taille_tab nombre d'éléments du tableau
 */
void afficher_tableau(const int tab[], size_t taille_tab) {
    cout << "[";
    for (size_t i = 0; i < taille_tab; ++i) {
        cout << tab[i];
        if (i != taille_tab - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * @brief supprime l'élément central d'un tableau
 * 
 * @param tab tableau à modifier
 * @param taille_tab nombre d'éléments du tableau
 */
void suppression_centre(int tab[], size_t& taille_tab) {
    if (taille_tab > 1) {
        size_t milieu = taille_tab / 2;

        int modificateur;
        if (taille_tab % 2 == 0) {
            modificateur = 2;   // indique que l'on devra modifier deux éléments
        } else {    // si le nombre d'éléments est impair
            modificateur = 1;   // indique que l'on devra modifier juste un élément
        }

        for (size_t i = milieu + 1; i < taille_tab; ++i) {  // on part depuis la case juste après celle située au centre
            tab[i - modificateur] = tab[i]; // la case actuelle (case après le centre) est copiée vers la ou les cases centrales (selon le modificateur)
        }
        taille_tab -= modificateur; // on réduit la taille du tableau
    }
}

int main() {
    int tab_impair[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t taille_tab_impair = sizeof tab_impair / sizeof (int); // calculer le nombre d'éléments du tableau
    int tab_pair[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t taille_tab_pair = sizeof tab_pair / sizeof (int);

    cout << endl << "****************** Tableau impair ******************" << endl;
    cout << "Avant modification : ";
    afficher_tableau(tab_impair, taille_tab_impair);
    suppression_centre(tab_impair, taille_tab_impair);
    cout << "Apres modification : ";
    afficher_tableau(tab_impair, taille_tab_impair);

    cout << endl << "****************** Tableau pair ******************" << endl;
    cout << "Avant modification : ";
    afficher_tableau(tab_pair, taille_tab_pair);
    suppression_centre(tab_pair, taille_tab_pair);
    cout << "Apres modification : ";
    afficher_tableau(tab_pair, taille_tab_pair);
}