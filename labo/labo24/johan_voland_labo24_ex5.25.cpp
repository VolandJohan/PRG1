/*
    file : johan_voland_labo24_ex5.25.cpp
    brief : tester l'égalité entre deux vecteurs
    author : Johan Voland
    date : 26.11.2021
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief afficher le contenu d'un vecteur
 * 
 * @param v vecteur à afficher
 */
void afficher_vector (const vector<int>& v) {
    cout << "[";
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i;
        if (i != v.end() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * @brief test si un vecteur est égal à un autre vecteur
 * 
 * @param v1 premier vecteur
 * @param v2 deuxième vecteur à comparer avec le premier
 * @return true si tous les éléments de v1 apparaissent au moins une fois dans v2
 * @return false si un des éléments de v1 n'apparait pas dans v2
 */
bool test_egalite(const vector<int>& v1, const vector<int>& v2) {
    for (size_t i = 0; i < v1.size(); ++i) {    // parcours tout le vecteur 1
        if (count(v2.begin(), v2.end(), v1.at(i)) == 0) {   //si la valeur actuelle de v1 n'apparait pas dans v2
            return false;
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