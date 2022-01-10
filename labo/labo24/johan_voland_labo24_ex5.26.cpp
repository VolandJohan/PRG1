/*
    file : johan_voland_labo24_ex5.26.cpp
    brief : effectuer diverses opérations
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
 * @brief calcul et affiche la somme des éléments d'un vecteur
 * 
 * @param v vecteur contenant les éléments
 */
void somme_de_v(const vector<int>& v) {
    int somme_de_v = 0;
    for (auto i = v.begin(); i != v.end(); ++i) {
        somme_de_v += *i;
    }
    cout << "Somme des elements de v = " << somme_de_v << endl;
}

/**
 * @brief calcul et affiche le nombre d'occurences d'un nombre donné
 * 
 * @param v vecteur contenant les éléments
 */
void calcul_occurences(const vector<int>& v) {
    int somme_occurences = 0;
    int occurence_a_calculer = 2;
    
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (*i == occurence_a_calculer) {
            ++somme_occurences;
        }
    }

    cout << "Occurences de " << occurence_a_calculer << " : " << somme_occurences << endl;
}

bool est_impair(int i) {
    return i % 2;
}

int main() {
    int tab[] = {3, 2, -5, 2, 4};
    size_t taille_tab = sizeof(tab) / sizeof(int);
    vector<int> v;

    // remplir v avec le contenu de tab
    for (size_t i = 0; i < taille_tab; ++i) {
        v.push_back(tab[i]);
    }

    cout << "Vecteur v initial :" << endl;
    afficher_vector(v);
    
    auto it = min_element(v.begin(), v.end());
    cout << "Plus petite valeur de v : " << *it << endl;
    it = max_element(v.begin(), v.end());
    cout << "Plus grande valeur de v : " << *it << endl;

    somme_de_v(v);

    calcul_occurences(v);

    // afficher le nombre de valeurs impaires
    cout << "Il y a " << count_if(v.begin(), v.end(), est_impair) << " nombres impairs." << endl;

    // trier et afficher v trié par ordre croissant
    cout << "Vecteur v trie par ordre croissant : " << endl;
    sort(v.begin(), v.end());
    afficher_vector(v);

    // trier et afficher v trié par ordre décroissant
    cout << "Vecteur v trie par ordre decroissant : " << endl;
    reverse(v.begin(), v.end());
    afficher_vector(v);
}