/**
 * @file corrections_diverses.cpp
 * @author Johan Voland
 * @brief Fichier pour écrire, exécuter et corriger divers exercices.
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int main()
{
    int i, j, k;
    i = 2; j = 3;
    k = i++ * ++j;
    cout << "C : i = " << i << " j = " << j << " k = " << k << endl;
}