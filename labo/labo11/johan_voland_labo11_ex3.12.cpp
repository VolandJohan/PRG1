/*
    file : johan_voland_labo_ex3.12.cpp
    brief : l'utilisateur entre 4 notes et 
            le programme en fait la moyenne et indique une apréciation
    author : Johan Voland
    date : 13.10.2021
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // entrée des données
    cout << "Entrez 4 notes : ";
    double note1, note2, note3, note4;
    cin >> note1 >> note2 >> note3 >> note4;

    // calcul
    double moyenne = (note1 + note2 + note3 + note4) / 4;

    string apreciation;
    // test de la moyenne selon barème
    if (moyenne > 5.5) {
        apreciation = " - Excellent";
    } else if (moyenne > 5.0 && moyenne <= 5.5) {
        apreciation = " - Tres bien";
    } else if (moyenne > 4.5 && moyenne <= 5.0) {
        apreciation = " - Bien";
    } else if (moyenne >= 4.0 && moyenne <= 4.5) {
        apreciation = " - Moyen";
    } else {    // si moyenne < 4.0
        apreciation = " - Insuffisant";
    }

    // affichage
    cout << fixed << setprecision(1) << "Moyenne = " << moyenne << apreciation;
}