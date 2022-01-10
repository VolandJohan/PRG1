/*
    file : johan_voland_labo14_ex3.29.cpp
    brief : Calcul du ppmc de nombres entrés par l'utilisateur
    author : Johan Voland
    date : 20.10.2021
*/

#include <iostream>

using namespace std;

int main() {
    // entrée des données
    cout << "Entrez deux nombres entiers > 0 : ";
    int a, b;
    cin >> a >> b;
    // on redemande si un 0 est écrit
    while (a <= 0 or b <= 0) {
        cout << "Erreur. Les nombres doivent etre > 0. Entrez a nouveau deux nombres : ";
        cin >> a >> b;
    }
    
    int ppmc = a * b;
    while (a != b) {
        if (a < b) {
            b -= a;
        } else {    // si a > b
            a -= b;
        }
    }

    cout << "ppmc : " << ppmc / a << endl;
}