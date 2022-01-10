/*
    file : johan_voland_labo24_ex5.23.cpp
    brief : test si les éléments d'un vecteur sont tous impairs
    author : Johan Voland
    date : 24.11.2021
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * @brief test si un nombre est impair
 * 
 * @param a nombre à tester
 * @return true si le nombre est impair
 * @return false si le nombre est pair
 */
bool est_impair(int a) {
    return a % 2;
}

int main() {
    vector<int> v{2, 3, 4, 5, 7, 11};
    int tab[] = {1, 3, 3};

    cout << "Vecteur impair ? : " << all_of(v.begin(), v.end(), est_impair) << endl;
    cout << "Tableau impair ? : " << all_of(tab, tab + 3, est_impair) << endl;
}