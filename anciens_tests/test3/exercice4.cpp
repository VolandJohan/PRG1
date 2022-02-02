#include <iostream>
#include "Mot.hpp"
using namespace std;

int main()
{
    Mot mots[] = {{"mot", 2}, {"mots", 5}, {"Mot"}};
    mots[1]++;
    for (Mot mot : mots)
        cout << mot << endl;
}