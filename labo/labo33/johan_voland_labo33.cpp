/*
    File :      johan_voland_labo33.cpp
    Brief :     Ce programme permet de résoudre des systèmes linéaires dont les dimensions sont définies par l'utilisateur.
    Autor :     Johan Voland
    Date :      19.01.2022
*/

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

template <typename T>
class Matrice {
 private :
    vector<vector<T>> matrice;
 public :
    // constructeur
    Matrice(size_t nb_lignes, size_t nb_colonnes);
    
    /* fonctions diverses */
    void afficher(size_t nb_lignes, size_t nb_colonnes) const;
    void pivot(size_t ligne, size_t colonne, size_t nb_lignes, size_t nb_colonnes);
};

/* constructeur */
template <typename T>
Matrice<T>::Matrice(size_t nb_lignes, size_t nb_colonnes) {
    /* redimensionnement de la matrice */
    matrice.resize(nb_lignes);
    for (size_t i = 0; i < matrice.size(); ++i) {
        matrice[i].resize(nb_colonnes);
    }

    for (size_t i = 0; i < nb_lignes; ++i) {
        for (size_t j = 0; j < nb_colonnes; ++j) {
            cout << "Introduisez l'element en " << i << "X" << j << endl;
            cin >> matrice.at(i).at(j);
        }
    }
}

/**
 * @brief Affiche le contenu de la matrice
 * 
 * @param nb_lignes Nombre de lignes de la matrice
 * @param nb_colonnes Nombre de colonne de la matrice
 */
template <typename T>
void Matrice<T>::afficher(size_t nb_lignes, size_t nb_colonnes) const {
    cout << "--------------------------------------------" << endl;
    for (size_t i = 0; i < nb_lignes; ++i) {
        for (size_t j = 0; j < nb_colonnes; ++j) {
            cout << scientific << matrice.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------" << endl;
}

/**
 * @brief Opération de pivotage, adaptation de la fonction de "pivote3_4.cpp"
 * 
 * @param ligne "ID" de la ligne de la matrice
 * @param colonne "ID" de la colonne de la matrice
 * @param nb_lignes Nombre de lignes de la matrice
 * @param nb_colonnes Nombre de colonne de la matrice
 */
template <typename T>
void Matrice<T>::pivot(size_t ligne, size_t colonne, size_t nb_lignes, size_t nb_colonnes) {
    for(size_t i = 0; i < nb_lignes; ++i) {
        if (i != ligne) {
            for (size_t j = 0; j < nb_colonnes; ++j) {
                if (j != colonne) {
                    matrice.at(i).at(j) = matrice.at(i).at(j) - matrice.at(i).at(colonne) * matrice.at(ligne).at(j) / matrice.at(ligne).at(colonne);
				}
            }
        }
    }
	
    for (size_t i = 0; i < nb_lignes; ++i) {
        if (i != ligne) {
            matrice.at(i).at(colonne) = -matrice.at(i).at(colonne) / matrice.at(ligne).at(colonne);
        }
    }
    for (size_t j = 0; j < nb_colonnes; ++j) {
        if (j != colonne) {
            matrice.at(ligne).at(j) = matrice.at(ligne).at(j) / matrice.at(ligne).at(colonne);
        }
    }
    matrice.at(ligne).at(colonne) = 1.0 / matrice.at(ligne).at(colonne);
}

int main() {
    /* entrée du nombre de lignes et colonnes */
    size_t nb_lignes, nb_colonnes;
    cout << "Entrez le nombre de lignes et de colonnes : ";
    cin >> nb_lignes >> nb_colonnes;

    /* création de la matrice */
    Matrice<double> matrice(nb_lignes, nb_colonnes);
    cout << "Avant pivot : " << endl;
    matrice.afficher(nb_lignes, nb_colonnes);

    /* pivot */
    for (size_t i = 0; i < nb_lignes; ++i) {
        matrice.pivot(i, i, nb_lignes, nb_colonnes);
    }
    /*cout << "Apres pivot : " << endl;
    matrice.afficher(nb_lignes, nb_colonnes);*/
}