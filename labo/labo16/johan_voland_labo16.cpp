/*
    file : johan_voland_labo16.cpp
    brief : Implanter la méthode de cryptographie à clé publique, connue sous le nom de RSA.
    author : Johan Voland
    date : 02.11.2021
*/

#include <iostream>
#include <random>
#include <cmath>

using namespace std;

// basé sur l'agorithme de la donnée du labo 15, les types sont sur 64bits pour éviter tout problème d'overflow
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

// basé sur l'agorithme du test rapide de primalité de la donnée
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

// code tiré de l'article wikipédia sur l'agotitme d'Euclide, basé sur des différences successives
int pgdc (int nbre1, int nbre2) {
    while (nbre1 != nbre2){ // tant que l'un des nombres est différent de l'autre ...
        // on vérifie lequel des deux est le plus grand et on soustrait de manière successive jusqu'à qu'il soit égal
        if (nbre1 > nbre2) {
            nbre1 -= nbre2;
        } else { // si nbre1 < nbre2
            nbre2 -= nbre1;
        }
    }
    // lorsque les deux nombres sont égaux, cela veut dire qu'on a le pgdc
    return nbre1;
}

// basé sur l'agotihtme d'Euclide étendu de la donnée
int algorithmeEuclideEtendu(int nbre1, int nbre2) {
    int r0 = nbre1;
    int r1 = nbre2;
    int d0 = 0;
    int d1 = 1;

    while (r1 != 0) {
        int q = r0 / r1;
        int rs = r0;
        int ds = d0;

        r0 = r1;
        d0 = d1;

        r1 = rs - q * r1;
        d1 = ds - q * d1;
    }

    if (d0 < 0) {
        d0 += nbre1;
    }

    return d0;
}

int main(){
    // inscription des deux nombres premiers
    int nbre_premier1, nbre_premier2;
    do {
        cout << "Entrez deux nombres premiers differents." << endl;
        cin >> nbre_premier1 >> nbre_premier2;
    } while (nbre_premier1 == nbre_premier2 || not testPrimalite(nbre_premier1) || not testPrimalite(nbre_premier2)); /* redemande si les nombres sont identiques ou s'ils
                                                                                                                        ne sont pas premiers */
    // inscription de e
    int e;
    do {     
        cout << "Entrez la valeur de e, elle doit etre premiere avec " << (nbre_premier1 - 1) * (nbre_premier2 - 1) << endl;      
        cin >> e;
    } while (pgdc(e, (nbre_premier1-1)*(nbre_premier2-1)) != 1); // vérification que e est premiers avec (nbre_premier1-1)*(nbre_premier2-1)

    // création de la clé publique
    int cle_publique = nbre_premier1 * nbre_premier2;

    // inscripion de message
    int message_original;
    do {
        cout << "Pour le message, entrez un nombre < " << cle_publique << endl;
        cin >> message_original;
    } while (message_original >= cle_publique); // vérifie que le message est < à la clé publique

    // calcul de la clé secrète selon l'algotithme d'Euclide étendu
    int cle_secrete = algorithmeEuclideEtendu((nbre_premier1 - 1) * (nbre_premier2 - 1), e);

    // décodage du message
    int message_code = expModulaire(message_original, e, cle_publique);
    int message_decode = expModulaire(message_code, cle_secrete, cle_publique);

    // affichage des deux clés
    cout << "Cle publique : " << cle_publique << endl;
    cout << "Cle secrete : " << cle_secrete << endl;

    // Vérifie que le message est décodé est identique à l'original et affiche le résultat
    if (message_decode == message_original) {
        cout << "Decodage reussi !" << endl << "Message original : " << message_original << endl << "Message decode : " << message_decode << endl;
    } else {    // si le message décodé != message original
        cout << "Decodage rate !" << endl << "Message original : " << message_code << endl << "Message decode : " << message_decode << endl;
    }
}