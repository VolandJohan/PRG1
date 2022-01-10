#include <iostream>

using namespace std;

/**
 * @brief remplir et afficher un tableau
 * 
 * @param tbl tableau à remplir
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

int main() {
    int t0[0];
    afficher_tableau(t0, 0);

    int t1[1] = {1};
    afficher_tableau(t1, 1);

    int t2[2] = {1, 2};
    afficher_tableau(t2, sizeof(t2) / sizeof(int)); 
}