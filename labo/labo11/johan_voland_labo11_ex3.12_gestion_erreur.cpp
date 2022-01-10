/*
    file : johan_voland_labo_ex3.12_gestion_erreur.cpp
    brief : L'utilisateur entre 4 notes et le programme en fait la moyenne et indique une apréciation.
            Cette version vérifie que l'utilisateur entre les bonnes données.
    author : Johan Voland
    date : 13.10.2021
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

const int nombre_de_notes = 4;

int main() {
    double somme_note = 0;
    int i;
    // on demande 4 notes
    for (i = 0; i <= 3; ++i){
        // entrée de la note
        double note;
        
        do {
            cout << "Entrez une note (les notes inferieurs a 1 ou superieur a 6 ne sont pas prises en compte) : ";
            cin >> note;
        } while (note < 0 || note > 6.0);   // si la note est invalide, elle est re-demandée
        
        somme_note += note; // additionne les notes pour le calcul de la moyenne
    }

    // calcul de la moyenne
    double moyenne = somme_note / nombre_de_notes;

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