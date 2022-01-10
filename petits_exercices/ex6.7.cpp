#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "ABCDEFGHIJZHUGl";
    string milieu;
    // position du caractère central de la chaîne
    size_t position = str.size() / 2;

    if (str.size() != 0) {  // test seulement si la chaîne contient des caractères
        if (str.size() % 2 != 0) {
            milieu = str.at(position);
        } else {
            milieu = str.at(position - 1);
            milieu += str.at(position);
        }

        cout << str << endl << milieu << endl;
    } else {
        cout << "la chaine est vide" << endl;
    }
}