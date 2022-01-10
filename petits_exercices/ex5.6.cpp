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

/**
 * @brief permuter la première et dernière valeur d'un tableau
 * 
 * @param tbl tableau à modifier
 * @param taille taille du tableau
 */
void permuter_debut_fin(int tbl[], size_t taille) {
    if (taille > 1) {   // vérifier que la tableau à au moins 1 élément
        int tmp = tbl[0];   // mettre position 0 dans variable temporaire
        tbl[0] = tbl[taille - 1];   // remplacer position 0 avec dernière position
        tbl[taille - 1] = tmp;  // remplacer dernière position avec la variable temporaire (qui était la position 0)
    }   
}

int main() {
    int tbl[] = {1, 2, 3, 4};
    size_t taille_tbl = sizeof tbl / sizeof (int);

    afficher_tableau(tbl, taille_tbl);

    permuter_debut_fin(tbl, taille_tbl);

    afficher_tableau(tbl, taille_tbl);
}