#include <iostream>

/*
    file : johan_voland_labo7.cpp
    brief : affichage et calcul de distances entrées par l'utilisateur
    author : Johan Voland
    date : 04.10.2021
*/

using namespace std;

const int MM_PAR_CM = 10;
const int CM_PAR_M = 100;
const int M_PAR_KM = 1000;

int main()
{
    // -- entrée des données --
    cout << "Entrez la premiere distance (km, m, cm, mm) : " << endl;
    int km1, m1, cm1, mm1;
    cin >> km1 >> m1 >> cm1 >> mm1;

    cout << "Entrez la deuxieme distance (km, m, cm, mm) : " << endl;
    int km2, m2, cm2, mm2;
    cin >> km2 >> m2 >> cm2 >> mm2;

    // -- calculs --
    // additions des valeurs entrées
    int somme_km = km1 + km2;
    int somme_m = m1 + m2;
    int somme_cm = cm1 + cm2;
    int somme_mm = mm1 + mm2;

    somme_km += somme_m / M_PAR_KM; // ajoute à la somme des km les potentiels m en trop (ex 1000m => +1km)
    
     /* si la somme des mètres est trop élevée (somme des m > 1000), le modulo de la somme des mètres avec le nbre de mètre par km
        permet d'avoir le reste qui correspond aux mètres restants après conversion en km */
    somme_m %= M_PAR_KM;
    // les calculs suivants ont le même principe que les deux calculs précédents
    somme_m += somme_cm / CM_PAR_M;
    
    somme_cm %= CM_PAR_M;
    somme_cm += somme_mm / MM_PAR_CM;
    
    somme_mm %= MM_PAR_CM;

    // -- affichage --
    cout << km1 << "km, " << m1 << "m, " << cm1 << "cm, " << mm1 << "mm + ";
    cout << km2 << "km, " << m2 << "m, " << cm2 << "cm, " << mm2 << "mm font : " << endl;
    cout << somme_km<< "km, " << somme_m << "m, " << somme_cm << "cm, " << somme_mm << "mm";
}