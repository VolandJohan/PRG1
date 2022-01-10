/*
    file : johan_voland_labo13_ex3.33.cpp
    brief : simulation du problème des 3 portes
    author : Johan Voland
    date : 19.10.2021
*/

#include <iostream>
#include <random>
#include <functional>

using namespace std;

const int nbre_de_parties = 1000;

int main() {
    // générer porte gagnante
    auto porte_gagnante = bind(uniform_int_distribution<int>(1, 3), mt19937(1));
    // candidat choisi une porte aléatoire
    auto porte_joueur = bind(uniform_int_distribution<int>(1, 3), mt19937(2));

    int victoire_fixe = 0; // compteur du nombre de victoires quand le joueur change pas
    int victoire_variable = 0; // compteur du nombre de victoires quand le joueur change

    // compter quand candidat choisir toujours la même porte
    int porte_choisie = porte_joueur();
    for (int i = 0; i <= nbre_de_parties; ++i) {
        if (porte_choisie == porte_gagnante()) {
            victoire_fixe++;
        }
    }

    // compter quand le joueur change tout le temps de porte
    for (int i = 0; i <= nbre_de_parties; ++i) {
        if (porte_joueur() == porte_gagnante()) {
            victoire_variable++;
        }
    }

    // comparaison de la meilleur méthode
    if (victoire_fixe > victoire_variable) {
        cout << "Les chances de gagner sont plus grandes si on ne change pas de porte. Cette methode a un taux de victoire de "<< (victoire_fixe * 100) / nbre_de_parties
            << "% alors que changer de porte a un taux de victoire de " << (victoire_variable * 100) / nbre_de_parties << "%." << endl;
    } else if (victoire_variable > victoire_fixe) {
        cout << "Les chances de gagner sont plus grandes si on change de porte. Cette methode a un taux de victoire de "<< (victoire_variable * 100) / nbre_de_parties
            << "% alors que changer de porte a un taux de victoire de " << (victoire_fixe * 100) / nbre_de_parties << "%." << endl;
    } else {    // si victoire_fixe = victoire_variable
        cout << "Les chances de gagner sont identiques si on choisi de garder sa porte ou de la changer. Les deux methodes ont un taux de victoire de "
            << (victoire_fixe * 100) / nbre_de_parties << "%." << endl;
    }
}