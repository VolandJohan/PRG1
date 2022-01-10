/*
    file : johan_voland_labo20.cpp
    brief : Calculer n! (donné par l'utilisateur) en utilisant un tableau.
    author : Johan Voland
    date : 16.11.2021
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
    }
    cout << "]" << endl;
}

/**
 * @brief calcul le factoriel d'un nombre
 * 
 * @param valeur nombre à calculer
 */
void factoriel(int valeur) {
    int tab[500] = {};
    int taille_tab = sizeof tab / sizeof (int);

    // affiche par défaut 1 (si la valeur < 2)
    tab[taille_tab - 1] = 1;
 
    // calcul jusqu'à atteindre la valeur entrée
    for (int x = 2; x <= valeur; ++x) {
        int carry = 0;
 
        // on multiplie chaque nombre du tableau par x
        for (int i = taille_tab - 1; i >= 0; --i)
        {
            int resultat = tab[i] * x + carry;
    
            tab[i] = resultat % 10; 
    
            // stock le résultat sur 10 dans le carry le décalage
            carry  = resultat / 10; 
        }
    
        while (carry > 0)
        {
            // met le modulo du carry dans le tableau
            tab[taille_tab] = carry % 10;
            carry = carry / 10;
            // pour changer de case
            --taille_tab;
        }
    }

    afficher_tableau(tab, taille_tab);
}

int main() {
    int valeur;
    do {
        cout << "Entrez une valeur positive : " << endl;
        cin >> valeur;
    } while (valeur < 0);

    factoriel(valeur);
}