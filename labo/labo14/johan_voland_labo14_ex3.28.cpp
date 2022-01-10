/*
    file : johan_voland_labo14_ex3.28.cpp
    brief : Calcul de la somme des n premiers termes de la série harmonique.
    author : Johan Voland
    date : 20.10.2021
*/

#include <iostream>

using namespace std;

float calcul_croissant_float(float n) {
    float somme;
    for (float i = 1; i <= n; ++i) {    // calcul de 1 jusqu'à n
        somme += 1 / i;
    }
    return somme;   
}

double calcul_croissant_double(double n) {
    double somme;
    for (double i = 1; i <= n; ++i) { // calcul de 1 jusqu'à n
        somme += 1 / i;
    }
    return somme;
}

float calcul_decroissant_float(float n) {
    float somme;
    for (float i = n; i >= 1; --i){ // calcul de n jusqu'à 1
        somme += 1 / i;
    }
    return somme;
}

double calcul_decroissant_double(double n) {
    double somme;
    for (double i = n; i >= 1; --i){ // calcul de n jusqu'à 1
        somme += 1 / i;
    }
    return somme;
}

int main() {
    // entrée des données
    cout << "Combien de termes voulez-vous ?" << endl;
    int n;
    cin >> n;
    while (n == 0) {    // pour empêcher qu'on entre 0
        cout << "Erreur. Le nombre doit etre > 0 : ";
        cin >> n;
    }
    
    // calcul et affichage des sommes en float
    cout << "En float croissant, la somme des " << n << " premiers termes vaut " << calcul_croissant_float(n) << endl;
    cout << "En float decroissant, la somme des " << n << " premiers termes vaut " << calcul_decroissant_float(n) << endl;

    // calcul et affichage des sommes en double
    cout << "En double croissant, la somme des " << n << " premiers termes vaut " << calcul_croissant_double(n) << endl;
    cout << "En double decroissant, la somme des " << n << " premiers termes vaut " << calcul_decroissant_double(n) << endl;
}