#include <iostream>
#include "Rationnel.hpp"
using Uint = uintmax_t;

using namespace std;

int main() {
    /* variables */
    /*Uint nbre3, nbre2, nbre25, nbre5;
    nbre3 = 3;
    nbre2 = 2;
    nbre25 = 25;
    nbre5 = 5;
    bool signe = true;*/

    /* création des nombres */
    /*Rationnel nombre1(nbre1, nbre2);
    Rationnel nombre2(nbre2, nbre1, signe);
    Rationnel nombre3();
    Rationnel nombre4(nbre3, nbre4);*/

    /* calculs */
    /*Rationnel nombre1(1, 2);
    Rationnel nombre2(nbre5, nbre2, signe);

    nombre1 -= nombre2;
    cout << nombre1 << endl;*/

    /* affichage */
    /*cout << "***** Affichage simple *****" << endl;
    cout << "Nombre 1 : " << nombre1 << endl;
    cout << "Nombre 2 : " << nombre2 << endl;
    cout << "Nombre 3 : " << nombre3 << endl;
    cout << "Nombre 4 : " << nombre4 << endl;*/

    /* booléens */
    Rationnel nbre1(1, 2);
    Rationnel nbre2(3, 5);
    if (nbre1 < nbre2) {
        cout << "nbre1 est plus petit" << endl;
    }
}