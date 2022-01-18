/*
    file :      johan_voland_labo31.cpp
    brief :     Permet à un utilisateur d'entrer une clé publique et une clé privée pour du cryptage rsa.
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
 * @param nbre1 
 * @param nbre2 
 * @return Uint 
 */
Uint algorithmeEuclideEtendu(const Uint &nbre1, const Uint &nbre2, Uint &modulo_inverse) {
    Uint quotient;
    Uint r = nbre1;
    Sint d = 0;

    Uint r_primaire = nbre2;
    Uint r_temp;
    Sint d_primaire = 1;
    Sint d_temp;

    while (r_primaire != 0) {
        quotient = r / r_primaire;
        r_temp = r;
        d_temp = d;

        r = r_primaire;
        d = d_primaire;

        r_primaire = r_temp - quotient * r_primaire;
        d_primaire = d_temp - quotient * d_primaire;
    }

    if (d < 0) {
        d += nbre1;
    }

    modulo_inverse = (Uint)d;

    return r;
}

bool test_primalite(const Uint &cle) {
    static std::random_device rd;
    // Maximum rotations for prime validation.
    static constexpr size_t MAX_PRIME_ROTATIONS = 10;

    if (cle < 2) {
        return false;
    } else if (cle == 2) {
        return true;
    }

    for (size_t i = 0; i < 10; i++) {
        // Generate an integer 2 <= n < prime
        auto generate =
            std::bind(std::uniform_int_distribution<size_t>(2, uint64_t(cle) - 1), std::mt19937(rd()));
        Uint a = generate();

        Uint testa = 43, testb = 74, testc = 75;
        cout << "Nombre genere pour le test : " << a << endl;
        cout << "A voir Cle - 1 : " << cle -1 << endl;
        cout << "Test mod : " << mod_pow(testa, testb, testc) <<endl;

        // Apply Fermat's Little Theorem.
        if (mod_pow(a, cle - 1, cle) != 1) {
            return false;
        }

        Uint q = 1, u = cle - 1;
        while (u % 2 == 0 && q == 1) {
            u /= 2;
            q = mod_pow(a, u, cle);

            if (q != 1 && q != cle - 1) {
                return false;
            }
        }
    }

    return true;
}

Uint generation_nbre_primaire(const size_t &taille_cle) {
    Uint cle;
    do {
        cle.randomize(taille_cle);
        cout << "cle random : " << cle << endl;
        cout << "test : " << test_primalite(cle) << endl;
    } while (test_primalite(cle) == false);

    return cle;
}

int main(){
    // inscription des deux nombres premiers
    Uint nbre_premier1, nbre_premier2;
    
    cout << "Entrez la taille des cles : " << endl;
    size_t taille_cle;
    while (!(cin >> taille_cle) || taille_cle <= 1) {
        if (taille_cle <= 1) {
            cout << "La cle doit etre plus que 1." << endl;
        } else {
            cout << "Nombre invalide." << endl;
        }
    }

    Uint n;
    cout << "Generation des cles ..." << endl;
    do {
        nbre_premier1 = generation_nbre_primaire(taille_cle / 2);
        cout << "nbre 1 : " << nbre_premier1 << endl;
        nbre_premier2 = generation_nbre_primaire(taille_cle - (taille_cle / 2));
        cout << "nbre 2 : " << nbre_premier2 << endl;
        n = nbre_premier1 * nbre_premier2;
    } while (nbre_premier1 == nbre_premier2 || n.size() != taille_cle);

    Uint phi = (nbre_premier1 - 1) * (nbre_premier2 - 1);

    // inscription de e
    Uint e;
    Uint d;
    do {
        e = generation_nbre_primaire(taille_cle / 2);
    } while (algorithmeEuclideEtendu(phi, e, d) != 1);

    cout << "Fini !" << endl;
    cout << "Taille de la cle : " << n << n.size() << endl;
    cout << "Cle publique : " << e << endl;
    cout << "Cle privee : " << e << endl;
}