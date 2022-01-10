 /*
    file : johan_voland_labo12_ex.3.19.cpp
    brief : l'utilisateur entre un montant et un taux d'intérêt et le programme
            indique combien de temps il faudra pour doubler le montant
    author : Johan Voland
    date : 15.10.2021
 */

#include <iostream>

using namespace std;

int main() {
    // entrée des données
    cout << "Entrez un montant : ";
    int montant;
    cin >> montant;
    cout << "Entrez un taux d'interet (en %): ";
    int taux;
    cin >> taux;

    int nbre_annee;
    int montant_double = montant * 2;

    // test et calcul du montant en fonction du taux
    while (montant < montant_double) {
        montant += (montant * taux) / 100;
        nbre_annee++;
    }

    // affichage
    cout << "Il vous faudra " << nbre_annee << " annees pour doubler votre montant.";
}