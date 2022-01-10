/*
    file : johan_voland_labo21_ex5.14.cpp
    brief : Écrire une fonction qui test si deux tableaux sont égaux.
    author : Johan Voland
    date : 17.11.2021
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief afficher le contenu d'un vector
 * 
 * @param v vector à afficher
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
 * @brief test si deux tebleaux sont égaux
 * 
 * @param v1 premier tableau
 * @param v2 deuxieme tableau
 * @return true si les deux tableaux sont égaux
 * @return false si le deux tableaux ne sont pas égaux
 */
bool test_egalite(const vector<int>& v1, const vector<int>& v2) {
    for (size_t i = 0; i < v1.size(); ++i) {
        size_t j = 0;
        while(v1.at(i) != v2.at(j)) {   // tant que la valeur de la case du tableau 1 est différente de celle de la case du tableau 2
            ++j;    // le tableau 2 va dans la case suivante et le test est de nouveau effectué
            if (j >= v2.size()) {   // si tout le tableau 2 à été parcouru et qu'il n'y a pas eu d'égalité
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<int> v1{3, 3, 1, 1, 2, 1};
    vector<int> v2{1, 2, 3};
    vector <int> v3{5, 6, 1, 7, 7, 5, 9, 12};

    cout << "************************** Tableaux egaux **************************" << endl;
    afficher_vector(v1);
    afficher_vector(v2);
    cout << "Resultat : " << test_egalite(v1, v2) << endl;

    cout << endl << "************************** Tableaux pas egaux **************************" << endl;
    afficher_vector(v1);
    afficher_vector(v3);
    cout << "Resultat : " << test_egalite(v1, v3) << endl;
}