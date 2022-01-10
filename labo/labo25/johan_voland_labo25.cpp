/*
    File :      johan_voland_labo25.cpp
    Brief :     Ce programme permet de résoudre des systèmes linéaires dont les dimensions sont définies par l'utilisateur.
    Autor :     Johan Voland
    Date :      03.01.2022
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/* Définition de types synonymes pour permettre la création de matrices à plusieurs dimensions. */
typedef vector<double> Ligne;
typedef vector<Ligne> Matrice;

/**
 * @brief Affiche le contenu d'une matrice.
 * 
 * @param m Matrice à afficher.
 * @param nb_lignes Nombre de lignes de la matrice.
 * @param nb_colonnes Nombre de colonnes de la matrice.
 */
void afficher_matrice(const Matrice& m, int nb_lignes, int nb_colonnes) {
    cout << "--------------------------------------------" << endl;
    for (size_t i = 0; i < nb_lignes; ++ i) {
        for (size_t j = 0; j < nb_colonnes; ++j) {
            cout << scientific << m.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------" << endl;
}

/**
 * @brief Opération de pivotage, adaptation de la fonction de "pivote3_4.cpp".
 * 
 * @param m Matrice à pivoter.
 * @param ligne Numéro de ligne entré par l'utilisateur.
 * @param colonne Numéro de colonne entré par l'utilisateur.
 * @param nb_lignes Nombre de lignes de la matrice.
 * @param nb_colonnes Nombre de colonnes de la matrice.
 */
void pivot(Matrice& m, size_t ligne, size_t colonne, int nb_lignes, int nb_colonnes) {
    for (size_t i = 0; i < nb_lignes; ++i) {
        if (i != ligne) {
            for (size_t j = 0; j < nb_colonnes; ++j) {
                if (j != colonne) {
                    m.at(i).at(j) = m.at(i).at(j) - m.at(i).at(colonne) * m.at(ligne).at(j) / m.at(ligne).at(colonne);
                }
            }
        }
    }
    for (size_t i = 0; i < nb_lignes; ++i) {
        if (i != ligne) {
            m.at(i).at(colonne) = -m.at(i).at(colonne) / m.at(ligne).at(colonne);
        }
    }
    for (size_t j = 0; j < nb_colonnes; ++j) {
        if (j != colonne) {
            m.at(ligne).at(j) = m.at(ligne).at(j) / m.at(ligne).at(colonne);
        }
    }
    m.at(ligne).at(colonne) = 1.0 / m.at(ligne).at(colonne);
}

int main() {
    /* Entrée du nombre de lignes et colonnes. */
    int nb_lignes, nb_colonnes;
    cout << "Entrez le nombre de lignes et de colonnes : ";
    cin >> nb_lignes >> nb_colonnes;

    /* Création de la matrice en fonction du nombre de lignes/colonnes. */
    Matrice matrice(nb_lignes, Ligne(nb_colonnes));

    /* Lecture des éléments de la matrice + vecteur */
    for (size_t i = 0; i < nb_lignes; ++i) {
        for (size_t j = 0; j < nb_colonnes; ++j) {
            cout << "Introduire l'element de la ligne " << i
                 << " et de la colonne " << j << endl;
            cin >> matrice.at(i).at(j);
        }
    }

    /* Pivotage. */
    for (size_t k = 0; k < nb_lignes; ++k) {
        pivot(matrice, k, k, nb_lignes, nb_colonnes);
    }
    afficher_matrice(matrice, nb_lignes, nb_colonnes);
}