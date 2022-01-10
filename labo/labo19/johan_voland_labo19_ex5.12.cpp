/*
    file : johan_voland_labo19_ex5.12.cpp
    brief : Supprimer un certain nombre de valeurs d'un tableau.
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
 * @brief supprime une valeur donnée du tableau
 * 
 * @param tab tableau à modifier
 * @param taille_tab nombre d'éléments du tableau
 * @param valeur valeur à supprimer du tableau
 */
void suppression_valeur(int tab[], size_t& taille_tab, int valeur) {
    for (size_t i = 0; i < taille_tab; ++i) {   // on parcours chaque élément du tableau
        while (tab[i] == valeur) {  // lorsque la valeur à supprimer est détectée ...
            for (size_t h = i; h < taille_tab; ++h) {   // ... une nouvelle boucle for parcours les éléments du tableau depuis le chiffre à supprimer ...
                tab[h] = tab[h +1]; // ... et remplace chaque valeur par celle du dessus
            }
            --taille_tab;
        }
    }
}

int main() {
    int tab[] = {1, 2, 1, 4, 5, 5, 7, 5, 9 ,10};
    size_t taille_tab = sizeof tab / sizeof (int);

    afficher_tab(tab, taille_tab);

    cout << "Entrez la valeur que vous voulez supprimer : ";
    int valeur;
    cin >> valeur;

    suppression_valeur(tab, taille_tab, valeur);
    cout << endl << "La valeur " << valeur << " a ete suprimee du tableau :" << endl;
    afficher_tab(tab, taille_tab);
}