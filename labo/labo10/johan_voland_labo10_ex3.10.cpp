/*
    file : johan_voland_labo10_ex3.10.cpp
    brief : l'utilisateur entre 3 chiffres et le programme les trient dans l'ordre croissant
    author : Johan Voland
    date : 12.10.2021
*/

#include <iostream>

using namespace std;

int main() {
    // entrée des données
    cout << "Entrez 3 chiffres : ";
    int a, b, c;
    cin >> a >> b >> c;

    int first, second, third;
    // test des différentes valeurs
    if (a <= b && a <= c) { // test de la première valeur
        first = a;
        // test de la seconde et dernière valeur
        if (b <= c) {
            second = b;
            third = c;
        } else {    // si c <= b alors c est le second chiffre et b le troisième
            second = c;
            third = b;
        }
    }
    if (b <= a && b <= c) {
        first = b;
        if (a <= c) {
            second = a;
            third = c;
        } else {    // si c <= a alors c est le second chiffre et a le troisième
            second = c;
            third = a;
        }
    }
    if (c <=a && c <= b) {
        first = c;
        if (a <= b) {
            second = a;
            third = b;
        } else { // si b <= a alors b est le second chiffre et a le troisième
            second = b;
            third = a;
        }
    }

    // affichage
    cout << "Apres tri : " << first << " " << second << " " << third;
}