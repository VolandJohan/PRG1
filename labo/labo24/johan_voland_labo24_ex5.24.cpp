/*
    file : johan_voland_labo24_ex5.24.cpp
    brief : concaténer deux vecteurs
    author : Johan Voland
    date : 24.11.2021
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

int main() {
    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 6, 6};

    afficher_vector(v2);
    auto it = copy(v1.begin(), v1.end(), v2.begin() + v2.size());
    v2.erase(it, v2.end());
    afficher_vector(v2);
}