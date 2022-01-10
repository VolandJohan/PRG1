#include <iostream>
#include <iomanip>

/*
    file : johan_voland_labo9.cpp
    brief : l'utilisateur peux choisir de convertir une valeur en celsius vers des Fahrenheit et vice-versa
    author : Johan Voland
    date : 06.10.2021
*/

using namespace std;

int main() { 
    // entrée du choix
    cout << "Transformation Fahrenheit <-> Degre Celsius" << endl;
    cout << "Introduire le sens de la transformation (vers C ou F) : ";
    char choix;
    cin >> choix;

    if (choix == 'c' or choix == 'C') {
        cout << "conversion vers des Celsius." << endl;
        
        // entrée des données
        cout << "Nombre de Fahrenheit :  ";
        double fahrenheit;
        cin >> fahrenheit;

        // calcul des fahrenheit en celcius selon la formule présente dans la donnée du labo
        double celcius = 5 * (fahrenheit - 32) / 9;

        cout << setprecision(2) << fixed; // afficher 2 chiffres après la virgule
        cout << fahrenheit << " Fahrenheit font " << celcius << " degres Celsius." << endl;
    }
    else if (choix == 'f' or choix == 'F') {
        cout << "conversion vers des Fahrenheit." << endl;

        // entrée des données
        cout << "Nonbre de Celsius : ";
        double celcius;
        cin >> celcius;

        /* calcul des celcius en fahrenheit grace à la modification de la formule inscrite
            dans la donnée du labo */
        double fahrenheit = (9 * celcius + 160) / 5;

        cout << setprecision(2) << fixed; // afficher 2 chiffres après la virgule
        cout << celcius << " degree Celsius font " << fahrenheit << " Fahrenheit." << endl;
    }
    else { // choix != 'c' or 'C' or 'f' or 'F'
        cout << "Entrez une lettre valide.";
    }
}