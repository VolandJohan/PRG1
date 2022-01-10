/*
    file : johan_voland_labo11_ex3.11.cpp
    brief : l'utilisateur entre un chiffre et le programme indique s'il est divisible par 3, 5 ou les deux
    auhtor : Johan Voland
    date : 13.10.2021
*/

#include <iostream>

using namespace std;

int main() {
    // entrée des données
    cout << "Entrez un nombre (superieur ou egal a 0) : ";
    int nombre;
    cin >> nombre;

    if ((nombre % 3) == 0 && (nombre % 5) == 0){    // test si le nombre est divisible par 3 et 5
        cout << nombre << " est un multiple de 3 et 5.";
    } else if ((nombre % 3) == 0) {  // sinon on test si le nombre est divisible par 3
        cout << nombre << " est un multiple de 3.";
    } else if ((nombre % 5) == 0) {  // sinon on test cette fois si le nombre est divisible par 5
        cout << nombre << " est un multiple de 5.";
    } else { // sinon il n'est pas divisible par 3 ou 5
        cout << nombre << " n'est pas un multiple de 3 ou 5.";
    }
}