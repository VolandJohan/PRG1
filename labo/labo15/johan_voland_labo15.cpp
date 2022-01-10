/*
    file : johan_voland_labo15.cpp
    brief : Implémenter une fonction PGDC de deux nombres en grâce à l'agorithme d'Euclide.
            Implémenter une seconde fonction d'exponentiation modulaire.
    author : Johan Voland
    date : 22.10.2021
*/

#include <iostream>
#include <cmath>

using namespace std;

int pgdc (int x, int y) {
    // code tiré de l'article wikipédia sur l'agotitme d'Euclide, basé sur des différences successives
    while (x != y){ // tant que l'un des nombres est différent de l'autre ...
        // on vérifie lequel des deux est le plus grand et on soustrait de manière successive jusqu'à qu'il soit égal
        if (x > y) {
            x -= y;
        } else { // si x < y
            y -= x;
        }
    }
    // lorsque les deux nombres sont égaux, cela veut dire qu'on a le pgdc
    return x;
}

// basé sur l'agorithme de la données
int expo_modulaire (int b, int e, int m){
    int r = 1;
    while (e > 0) {
        if (e % 2 == 0) {
            b = (b*b) % m;
            e /= 2;
        } else {
            r = r * b % m;
            e -= 1;
        }
    }
    return r;
}

int main() {
    // entrée des données pour le PGDC
    cout << "Entrez deux valeurs pour le PGDC : ";
    int x, y;
    cin >> x >> y;

    // entrée des données pour l'exponentiation
    cout << "Pour l'exponentiation modulaire, entrez les valeurs de b, e et m (positives) : ";
    int b, e, m;
    cin >> b >> e >> m;

    // affichage
    cout << "Le PGDC de " << x << " et " << y << " est " << pgdc(x, y) << endl;
    cout << "Le resultat de l'exponentiation modulaire est " << expo_modulaire(b, e, m);
}