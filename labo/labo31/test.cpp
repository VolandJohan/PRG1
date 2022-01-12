#include <iostream>
#include "Uint.hpp"
using namespace std;

int main() {
    /* Test de la conversion vers unit_64t */
    Uint val = 45;
    cout << "Avant conversion : " << val << endl;
    cout << "Apres conversion : " << uint64_t(val) << endl;

    /* Test écriture. */
    cin >> val;
    cout << "Apres ecriture : " << val << endl;

    /* Test exponentielle modulaire. */
    Uint base = 30;
    Uint expo = 4;
    Uint modulo = 7;

    cout << "Expo_mod : " << mod_pow(base, expo, modulo) << endl;
}