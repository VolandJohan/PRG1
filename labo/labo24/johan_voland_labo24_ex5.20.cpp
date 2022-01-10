/*
    file : johan_voland_labo24_ex5.20.cpp
    brief : Implémentation d'un carré magique normal.
    author : Johan Voland
    date : 24.11.2021
*/

#include <iostream>
#include <vector>

using namespace std;

// définir un nouveau type Matrice afin d'afficher des vecteurs à deux dimensions
typedef vector<int> Ligne;
typedef vector<Ligne> Matrice;

/**
 * @brief afficher le contenu d'une matrice
 * 
 * @param m matrice à afficher
 */
void afficher_matrice(const Matrice& m) {
    for (size_t l = 0; l < m.size(); ++l) {
        for (size_t c = 0; c < m.size(); ++c) {
            cout << m.at(l).at(c) << " ";
        }
        cout << endl;
    }
}

/**
 * @brief remplir le tableau selon l'algorithme de contruction de carré magique d'ordre impair
 * 
 * @param nombre nombre de colonne et de lignes
 * @param m tableau(matrice) à remplir
 */
void carre_magique(int nombre, Matrice& m) {
    int ligne = nombre - 1;
    int colonne = nombre / 2;

    for (size_t k = 1; k <= nombre*nombre; ++k) {
        m.at(ligne).at(colonne) = k;
        if (m.at((ligne+1)%nombre).at((colonne+1)%nombre) != 0) {
            --ligne;
        } else {
            ++ligne;
            ++colonne;
        }

        // si les pointeurs dépassent le nombre max de lignes/colonnes du tableau
        if (ligne == nombre) {
            ligne = 0;
        }
        if (colonne == nombre) {
            colonne = 0;
        }
    }
}

int main() {
    int ordre;
    cout << "Entrez l'ordre du carre magique souhaite (entier impaire > 0) : ";
    cin >> ordre;
    while (ordre % 2 == 0) {
        cout << "Saisie incorrecte. Veuillez recommencer : " << endl;
        cin >> ordre;
    }

    Matrice tab(ordre, Ligne(ordre));
    carre_magique(ordre, tab);
    afficher_matrice(tab);
}