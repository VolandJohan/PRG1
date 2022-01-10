/*
    file :      johan_voland_labo30.cpp
    brief :     Intégrer une fonction de génération de nombres aléatoires premiers à la classe Uint.
    author :    Johan Voland
    date :      21.12.2021
*/

#include <iostream>
#include "Uint.hpp"

#include <random>
#include <functional>

using namespace std;

/**
 * @brief Retourne le quotient et le reste de la division de 2 Uint.
 *        Basé sur l'agorithme de la donnée du labo.
 * 
 * @param dividende 
 * @param diviseur 
 */
void division_reste (Uint dividende, Uint diviseur) {
    Uint puissance2 = 1;
    Uint b = diviseur;
    while (b <= dividende) {
        puissance2 *= 2;
        b *= 2;
    }

    Uint quotient = 0;
    Uint reste = dividende;

    while (reste >= diviseur) {
        b /= 2;
        puissance2 /= 2;
        if (reste >= b) {
            quotient += puissance2;
            reste -= b;
        }
    }

    cout << "Quotient : " << quotient << endl;
    cout << "Reste : " << reste << endl;
}

/**
 * @brief Calcul l'exponentielle modulaire en fonction de différentes valeurs.
 * 
 * @param base 
 * @param exponentiel 
 * @param modulo 
 * @return int Résultat du calcul.
 */
int expModulaire (int64_t base, int64_t exponentiel, int64_t modulo){
    int64_t result = 1;
    while (exponentiel > 0) {
        if (exponentiel % 2 == 0) {
            base = (base*base) % modulo;
            exponentiel /= 2;
        } else {
            result = result * base % modulo;
            exponentiel -= 1;
        }
    }
    return result;
}

/**
 * @brief Test si un nombre est premier.
 * 
 * @param nbre Nombre à tester.
 * @return true Si le nombre est un nombre premier.
 * @return false Si le nombre n'est pas un nombre premier.
 */
bool testPrimalite(int nbre) {
    if (nbre < 2) {
        return false;
    }
    if (nbre == 2) {
        return true;
    }

    for (int i = 0; i < 10; ++i) {
        // nombre aléatoire
        int a = rand()%(nbre - 1) + 1;

        if (expModulaire(a, nbre - 1, nbre) != 1) {
            return false;
        }

        int q = 1;
        int u = nbre - 1;

        while (u%2 == 0 && q == 1) {
            u /= 2;
            q = expModulaire(a, u, nbre);

            if (q != 1 && q != nbre - 1) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief Génère un nombre premier aléatoire, sa taille est entrée par l'utilisateur.
 * 
 * @param nombre_de_chiffres Nombre de chiffre du nombre, entré préalablement par l'utilisateur.
 * @return Uint Nombre premier aléatoire.
 */
int valeur_aleatoire (int nombre_de_chiffres) {
    int nombre_aleatoire = bind(uniform_real_distribution<Uint>(1, 9999), mt19937(1));

    return (int)nombre_aleatoire;
}

int main() {
    Uint nombre = 6234;
    Uint diviseur = 67;

    cout << "Entrez le nombre de chiffres des valeurs" << endl;
    int nombre_de_chiffres;
    cin >> nombre_de_chiffres;

    nombre = valeur_aleatoire(nombre_de_chiffres);

    cout << nombre << " / " << diviseur << endl;

    division_reste(nombre, diviseur);
    cout << "Division entiere = " << nombre.division_entiere(diviseur) << endl;
    cout << "Reste = " << nombre.reste(diviseur) << endl;
}