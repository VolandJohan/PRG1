/*
    file :      johan_voland_labo31.cpp
    brief :     Permet à un utilisateur de générer une clé publique et une clé privée pour du cryptage rsa.
    author :    Johan Voland
    date :      17.01.2022
*/

#include <iostream>
#include <random>
#include <cmath>
#include "Uint.hpp"
#include "Sint.hpp"
#include <functional>

using namespace std;

/**
 * @brief Effectue l'algorithme d'Euclide étendu.
 * 
 * @param nbre1 Premier nombre de l'équation
 * @param nbre2 Deucième nombre de l'équation
 * @return Uint Résultat de l'équation
 */
Uint algorithmeEuclideEtendu(Uint nbre1, Uint nbre2) {
    Uint r0 = nbre1;
    Uint r1 = nbre2;
    Sint d0 = 0;
    Sint d1 = 1;

    while (r1 != 0) {
        Uint q = r0 / r1;
        Uint rs = r0;
        Sint ds = d0;

        r0 = r1;
        d0 = d1;

        r1 = rs - q * r1;
        d1 = ds - q * d1;
    }

    if (d0 < 0) {
        d0 += nbre1;
    }

    return (Uint)d0;
}

/**
 * @brief test si un nombre est premier, basé sur le labo16
 * 
 * @param nombre Nombre à tester
 * @return true Si le nombre est premier
 * @return false Si le nombre n'est pas premier
 */
bool test_primalite(const Uint &nbre) {
    if (nbre < 2) {
        return false;
    }
    if (nbre == 2) {
        return true;
    }

    for (int i = 0; i < 10; ++i) {
        // nombre aléatoire
        auto generation = bind(uniform_int_distribution<size_t>(2, (uint64_t)nbre - 1), mt19937(1));
        int a = generation();

        if (mod_pow(a, nbre - 1, nbre) != 1) {
            return false;
        }

        Uint q = 1;
        Uint u = nbre - 1;

        while (u%2 == 0 && q == 1) {
            u /= 2;
            q = mod_pow(a, u, nbre);

            if (q != 1 && q != nbre - 1) {
                return false;
            }
        }
    }
    return true;
}

/**
 * @brief génère un nombre premier
 * 
 * @param taille_cle Taille du nombre
 * @return Uint Nombre premier
 */
Uint generation_nbre_primaire(const size_t &taille_cle) {
    Uint cle;
    do {
        cle.randomize(taille_cle);
    } while (test_primalite(cle) == false);

    return cle;
}

int main(){
    Uint nbre_premier1, nbre_premier2;
    
    /* inscription de la taille des clés */
    cout << "Entrez la taille des cles : " << endl;
    size_t taille_cle;
    while (!(cin >> taille_cle) or taille_cle <= 1) {
        if (taille_cle <= 1) {
            cout << "La cle doit etre plus grande que 1." << endl;
        } else {
            cout << "Nombre invalide." << endl;
        }
    }

    /* génération des nombres premiers */
    Uint n;
    cout << "Generation des cles ..." << endl;
    do {
        nbre_premier1 = generation_nbre_primaire(taille_cle / 2);
        nbre_premier2 = generation_nbre_primaire(taille_cle - (taille_cle / 2));
        n = nbre_premier1 * nbre_premier2;
    } while (nbre_premier1 == nbre_premier2 or n.size() != taille_cle);
    
    /* calcul des clés */
    Uint phi = (nbre_premier1 - 1) * (nbre_premier2 - 1);
    Uint e;
    do {
        e = generation_nbre_primaire(taille_cle / 2);
    } while (algorithmeEuclideEtendu(phi, e) != 1);

    /* affichage des résultats */
    cout << "Fini !" << endl;
    cout << "Taille de la cle : " << n << n.size() << endl;
    cout << "Cle publique : " << algorithmeEuclideEtendu(phi, e) << endl;
    cout << "Cle privee : " << e << endl;
}