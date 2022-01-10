/*
    file :      johan_voland_labo22.cpp
    brief :     Effectue la cible de Fibonacci selon des données entrées par l'utilsateur.
    author :    Johan Voland
    date :      19.11.2021
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Affiche le contenu d'un vector.
 * 
 * @param v Vector à afficher.
 */
void afficher_vector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
    }
    cout << "]" << endl;
}

/**
 * @brief Effectue le report d'une valeur stockée dans un vector, c'est à dire
 *        déplacer les nombres lorsque le nombre est plus de 1 chiffre.
 * 
 * @param a Vector contenant la valeur.
 * @return vector<int>& Vector contenant la valeur après modification.
 */
vector<int>& report(vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (i == a.size() - 1) {
            if (a.at(i) >= 10) {
                a.push_back(a.at(i) / 10);
            } else {}
        } else {
            a.at(i + 1) += a.at(i) / 10;
        }
        a.at(i) %= 10;
    }
    return a;
}

/**
 * @brief Additionne deux nombres stockés dans des vector.
 * 
 * @param a Premier vector.
 * @param b Deuxième vector.
 * @return vector<int> Vector contenant le résultat de l'addition.
 */
vector<int> add (vector<int> a, const vector<int>& b) {
    for (size_t i = a.size(); i < b.size(); ++i) {
        a.push_back(0);
    }
    // addition des valeurs dans chaque case de a avec celle de b
    for (size_t i = 0; i < b.size(); ++i) {
        a.at(i) += b.at(i);
    }
    // pour qu'il y ait un nombre par case, un report des valeurs à deux chiffre ou plus doit être effectué
    return report(a);
}

/**
 * @brief Effectue la suite de Fibonacci en fonction d'une valeur entrée.
 * 
 * @param fm1 Vector possèdant un des résultats de la suite de Fibonacci (le premier terme de la suite).
 * @param fm2 Vector possèdant un des résultats de la suite de Fibonacci (le deuxième terme de la suite).
 * @param n Valeur indiquant jusqu'où la suite de Fibonacci doit aller (Fn).
 * @return vector<int> Résultat de la suite.
 */
vector<int> fibonacci (vector<int> fm1, vector<int> fm2, int n) {
    vector<int> f;
    
    // calcul de la suite de Fibonacci en fonction de n
    for (int i = 2; i <= n; ++i) {
        // additionne deux valeurs contenues dans des vector
        f = add(fm1, fm2);
        // mettre "à jour" les valeurs des vector après l'opération
        fm1 = fm2;
        fm2 = f;
    }

    // le résultat apparait par défaut à l'envers (il se lit de droite à gauche), un "reverse()" résout ce problème
    reverse(f.begin(), f.end());
    return f;
}

int main() {
    // vecteur contenant le résultat de la suite de Fibonacci pour 0
    vector<int> fm1(1, 0);
    // vecteur contenant le résultat de la suite de Fibonacci pour 1
    vector<int> fm2(1, 1);

    int n;
    cout << "Entrez une valeur : ";
    cin >> n;

    afficher_vector(fibonacci(fm1, fm2, n));
}