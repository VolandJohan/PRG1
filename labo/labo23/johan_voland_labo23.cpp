/*
    date :      johan_voland_labo23.cpp
    brief :     Effectue la multiplication de deux entiers longs.
    author :    Johan Voland
    date :      30.12.2021
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
void afficher_vector (const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v.at(i);
        if (i != v.size() - 1) {
            cout << ", ";
        }
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
 * @brief Effectue la multiplication d'un entier long avec un simple chiffre.
 * 
 * @param a Vector contenant l'entier long.
 * @param b Vector contenant le chiffre simple.
 * @return vector<int> Résultat des opérations.
 */
vector<int> mult_simple(vector<int> a, const int b) {
    int carry = 0;
    // multiplier chaque case par la dernière valeur de b
    for (size_t i = a.size(); i > 0; --i) {
        int result = a.at(i - 1) * b + carry;

        a.at(i - 1) = result % 10;

        carry = result / 10;
    }

    // ajouter les carry
    reverse(a.begin(), a.end());
    while (carry > 0) {
        a.push_back(carry % 10);
        carry = carry / 10;
    }
    reverse(a.begin(), a.end());

    return a;
}

/**
 * @brief Additionne deux nombres stockés dans des vector.
 * 
 * @param a Premier vector.
 * @param b Deuxième vector.
 * @return vector<int> Vector contenant le résultat de l'addition.
 */
vector<int> add (vector<int> a, vector<int> b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (size_t i = a.size(); i < b.size(); ++i) {
        a.push_back(0);
    }
    // addition des valeurs dans chaque case de a avec celle de b
    for (size_t i = 0; i < b.size(); ++i) {
        a.at(i) += b.at(i);
    }
    // pour qu'il y ait un nombre par case, un report des valeurs à deux chiffre ou plus doit être effectué
    a = report(a);
    reverse(a.begin(), a.end());
    return a;
}

/**
 * @brief Multiplie deux entiers longs.
 * 
 * @param a Vector contenant le premier entier.
 * @param b Vector contenant le deuxième entier.
 * @return vector<int> Résultat de la multiplication.
 */
vector<int> mult(vector<int> a, const vector<int>& b) {
    int val = b.back();
    vector<int> v1 = mult_simple(a, val);
    vector<int> v2;

    for (int i = b.size() - 2; i >= 0; --i) {
        a.push_back(0);
        v2 = mult_simple(a, b.at(i));
        v1 = add(v1, v2);
    }

    return v1;
}

int main() {
    vector<int> n1 = {7, 6, 5, 4};
    vector<int> n2 = {3, 6, 9};
    vector<int> result;

    result = mult(n1, n2);
    afficher_vector(result);
}