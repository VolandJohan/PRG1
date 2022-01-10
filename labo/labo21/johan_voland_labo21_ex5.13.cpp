/*
    file : johan_voland_labo21_ex5.13.cpp
    brief : créer une fonction qui supprime les doublons d'un tableau
    author : Johan Voland
    date : 17.11.2021
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief affiche le contenu d'un tableau de type vector
 * 
 * @param v tableau à afficher
 */
void afficher_vector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * @brief détecte si un doublon est présent et supprime ce dernier
 * 
 * @param v tableau à tester
 */
void suppression_doublons(vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) { // on va parcourir le tableau ...
        size_t compteur = i + 1;   // ... une nouvelle valeur est créée en fonction de la case actuelle
        while (compteur < v.size()) { // cette nouvelle valeur parcours le tableau
            if (v[i] == v[compteur]) { // chaque fois qu'un doublon avec la case actuelle est détecté ...
                v.erase(v.begin() + compteur); // ... ce dernier est supprimé (avec la méthode erase())
                --compteur;    // le compteur est décrémenté pour tester la valeur décalée
            }
            ++compteur;    // le compteur est incrémenté pour passer à la case suivante
        }
    }
}

int main() {
    vector<int> v = {1, 2, 3, 5, 2, 6, 1, 8, 90, 3, 3};

    cout << endl << "******************** Avant test ********************" << endl;
    afficher_vector(v);
    cout << endl << "******************** Apres test ********************" << endl;
    suppression_doublons(v);
    afficher_vector(v);
}