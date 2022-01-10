/*
    file : johan_voland_labo10_ex3.9.cpp
    brief : l'utilisateur entre 3 entiers et le programme affiche le plus petit d'entre eux
    author : Johan Voland
    date : 12.10.2021
*/

#include <iostream>

using namespace std;

int main(){
    // entrée des données
    cout << "Entrez 3 chiffres : ";
    int a, b, c;
    cin >> a >> b >> c;

    // test des différentes valeurs
    if (a <= b && a <= c) {
        cout << a << " est le minimum.";
        return 0; // pour mettre fin au programme et empêcher les autres boucles de se faire
    }
    if (b <= a && b <= c) {
        cout << b << " est le minimum.";
        return 0;
    }
    if (c <= a && c <= b) {
        cout << c << " est le minimum.";
        return 0;
    }
}