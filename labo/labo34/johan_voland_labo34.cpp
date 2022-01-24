#include <iostream>
#include "Rationnel.hpp"
using Uint = uintmax_t;

using namespace std;

int main() {
    Uint nbre1, nbre2, nbre3, nbre4;
    nbre1 = 3;
    nbre2 = 2;
    nbre3 = 25;
    nbre4 = 5;
    bool signe = true;

    Rationnel nombre1(nbre1, nbre2);
    Rationnel nombre2(nbre2, nbre1, signe);
    Rationnel nombre3();
    Rationnel nombre4(nbre3, nbre4);

    cout << "Nombre 1 : " << nombre1 << endl;
    cout << "Nombre 2 : " << nombre2 << endl;
    cout << "Nombre 3 : " << nombre3 << endl;
    cout << "Nombre 4 : " << nombre4 << endl;
}