#include <iostream>
#include "Rationnel.hpp"

using namespace std;

int main() {
    Rationnel nbre1(5, 1, false);
    Rationnel nbre2(6, 1, false);
    //Rationnel nbre3(7, 1, false);
    Rationnel result;

    result = nbre1 - nbre2;
    cout << nbre1 << " - " << nbre2 << " = " << result << endl;

    result = nbre1 / nbre2;
    cout << nbre1 << " / " << nbre2 << " = " << result << endl;

    result = nbre1 * nbre2;
    cout << nbre1 << " * " << nbre2 << " = " << result << endl;
}