#include <iostream>

using namespace std;

/**
 * @brief afficher un tableau
 * 
 * @param tbl tableau à afficher
 * @param taille nombre d'éléments du tableau
 */
void afficher_tableau(const int tbl[], size_t taille) {
    cout << "[";
    for (size_t i = 0; i < taille; ++i) {
        cout << tbl[i];
        if (i != taille - 1) { // Si on n'est pas à la fin du tableau, on met une virgule.
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * @brief remplacer toutes les valeurs paires du tableau par un nombre donné
 * 
 * @param tbl tableau à modifier
 * @param taille nombre d'éléments du tableau
 * @param valeur_a_remplacer valeur à inscrire à la place d'un nombre pair
 */
void remplacer_pair(int tbl[], size_t taille, int valeur_a_remplacer) {
    for (size_t i = 0; i < taille; ++i) {   // parcourir chaque case du tableau
        if (tbl[i] % 2 == 0) {  // si la valeur est pair
            tbl[i] = valeur_a_remplacer;
        }
    }
}

int main() {
    int tbl[] = {1, 2, 3, 4};
    size_t taille_tbl = sizeof tbl / sizeof (int);

    afficher_tableau(tbl, taille_tbl);

    int valeur = 69;
    remplacer_pair(tbl, taille_tbl, valeur);

    afficher_tableau(tbl, taille_tbl);
}