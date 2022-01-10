/*
    file : johan_voland_labo19_ex5.11.cpp
    brief : calcul de la somme altérée de tous les éléments d'un tableau
    author : Johan Voland
    date : 16.11.2021
*/

#include <iostream>

using namespace std;

/**
 * @brief affiche le contenu d'un tableau
 * 
 * @param tab tableau à afficher
 * @param taille_tab nombre d'éléments du tableau
 */
void afficher_tab(const int tab[], size_t taille_tab) {
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
 * @brief calcul la somme alternée d'un tableau
 * 
 * @param tab tableau à modifier
 * @param taille_tab nombre d'éléments du tableau
 */
void somme_alternee(int tab[], size_t& taille_tab) {
    int result;
    if (taille_tab == 0) {  // si le tableau est vide, affiche un 0
        result = 0;
    } else {
        result = tab[0];    // le résultat prend le premier nombre du tableau
        for (size_t i = 0; i < taille_tab - 1; ++i) {
            if (i % 2 == 0) {   // si la case est paire, le résultat est soustrait par le nombre suivant
                result -= tab[i + 1];
            } else {    // sinon, le résultat est additionné avec le nombre suivant
                result += tab[i + 1];
            }
        }
    }
    // une fois les calculs effectué, on modifie la taille du tableau pour qu'il n'est qu'une case et on met le résultat du calcul dans cette dernière
    taille_tab = 1;
    tab[0] = result;
}

int main() {
    int tab[] = {1, 2, 3, 4};
    size_t taille_tab = sizeof tab / sizeof (int);  // calcul du nombre d'éléments du tableau

    cout << endl << "*************************** avant calcul ***************************" << endl;
    afficher_tab(tab, taille_tab);
    somme_alternee(tab, taille_tab);
    cout << endl << "*************************** apres calcul ***************************" << endl;
    afficher_tab(tab, taille_tab);
}