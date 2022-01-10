/*
    file : johan_voland_labo19_ex5.10.cpp
    brief : Écrire une fonction qui vérifie que les éléments d'un tableau sont triés de manière croissante.
    author : Johan Voland
    date : 12.11.2021
*/

#include <iostream>

using namespace std;

/**
 * @brief afficher les éléments d'un tableau
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
 * @brief test si les nombres d'un tableau sont triés par ordre croissant
 * 
 * @param tab tableau contenant à vérifier
 * @param taille_tab nombre d'éléments du tableau
 * @return true si les nombres dans le tableau sont triés par ordre croisant
 * @return false si les nombres dans le tableau ne sont par triés par ordre croissant
 */
bool test_ordre_croissant (const int tab[], size_t taille_tab) {
    bool result;
    if (taille_tab <= 1) {
        result = true;
    } else {
        for (size_t i = 0; i < taille_tab - 1; ++i) {
            if (tab[i] < tab[i + 1]) {
                result = true;
            } else {
                result = false;
            }
        }
    }
    return result;
}

int main() {
    int tab_croissant[] = {1, 2, 4, 5, 6};
    int taille_tab_croissant = sizeof tab_croissant / sizeof (int);

    int tab_vide[] = {};
    int taille_tab_vide = sizeof tab_vide / sizeof (int);

    int tab_desordonne[] = {9, 65, 23, 2, 6, 90, 23};
    int taille_tab_desordonne = sizeof tab_desordonne / sizeof (int);

    cout << endl << "************************ tableau croissant ************************" << endl;
    afficher_tableau(tab_croissant, taille_tab_croissant);
    cout << "resultat du test : " << test_ordre_croissant(tab_croissant, taille_tab_croissant) << endl;

    cout << endl << "************************ tableau vide ************************" << endl;
    afficher_tableau(tab_vide, taille_tab_vide);
    cout << "resultat du test : " << test_ordre_croissant(tab_vide, taille_tab_vide) << endl;

    cout << endl << "************************ tableau desordonne ************************" << endl;
    afficher_tableau(tab_desordonne, taille_tab_desordonne);
    cout << "resultat du test : " << test_ordre_croissant(tab_desordonne, taille_tab_desordonne) << endl;
}