/*
    file : johan_voland_labo12_ex.3.20.cpp
    brief : Afficher les nombres de 20 à 1 par lot de 3.
    author : Johan Voland
    date : 15.10.2021
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int val_max = 20;

int main() {
    // -------------------------------------------------------- avec boucle WHILE ---------------------------------------
    /*int i = val_max;
    while (i > 1) {
        int j = 0;
        while (j < 3) { // pour afficher 3 chiffres par ligne            
            if (i != 0) { 
                cout << setw(2) << i << " ";
            } else {    // si i == 0 on affiche un caractère vide à la place
                cout << "";
            }
            j++;
            i--;
        }
        cout << endl;
    }*/

    // -------------------------------------------------- avec boucle FOR ------------------------------------------
    for (int i = val_max; i > 1; i -= 3) {  
        for (int j = 0; j <= 2; j++) {
            /* i - j permet d'afficher 3 chiffres différents par ligne. Si on ne mettait que i 
                alors le même chiffre serait affiché 3 fois sur la même ligne */
            if ((i - j) != 0) {
                cout << setw(2) << i - j << " ";
            } else {    // si (i - j) == 0 on affiche un caractère vide à la place du 0
                cout << "";
            }
        }
        cout << endl;
    }
}