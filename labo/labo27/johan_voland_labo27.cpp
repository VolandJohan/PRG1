/*
    file : johan_voland_labo27.cpp
    brief : utiliser la fonction du labo16 pour crypter un texte
    author : Johan Voland
    date : 03.12.2021
*/

#include <iostream>
#include <random>
#include <cmath>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

const int NBRE_PREMIER_1 = 7919;
const int NBRE_PREMIER_2 = 7907;
const int E = 62552200;

ofstream fichier_out;
ifstream fichier_in;

/**
 * @brief calcule exponentielle modulaire selon algorithme du labo15
 * 
 * @param base base de l'équation
 * @param exponentiel exponentielle de l'équation
 * @param modulo modulo de l'équation
 * @return int résultat des calculs
 */
int exp_modulaire (int base, int exponentiel, int modulo){
    int32_t result = 1;
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
 * @brief effectue l'agorithme d'Euclide étendu, indiqué dans la donnée du labo
 * 
 * @param nbre1 premier nombre de l'agorithme
 * @param nbre2 deuxième nombre de l'agorithme
 * @return int résultat des calculs
 */
int algorithme_euclide_etendu(int nbre1, int nbre2) {
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

/**
 * @brief code un charactère (depuis un string) dans un fichier
 * 
 * @param i position du char par rapport au string
 */
void code_char(size_t i) {
    // création de la clé publique
    int cle_publique = NBRE_PREMIER_1 * NBRE_PREMIER_2;

    // calcul de la clé secrète selon l'algotithme d'Euclide étendu
    int cle_secrete = algorithme_euclide_etendu((NBRE_PREMIER_1 - 1) * (NBRE_PREMIER_2 - 1), E);

    // codage du message
    //i *= 256;
    int message_code = exp_modulaire(i, E, cle_publique);
    fichier_out << message_code;
}

/**
 * @brief décode un nombre dans un fichier
 * 
 * @param i position du nombre dans la chaîne
 */
void decode_char(size_t i) {
    int cle_publique = NBRE_PREMIER_1 * NBRE_PREMIER_2;
    int cle_secrete = algorithme_euclide_etendu((NBRE_PREMIER_1 - 1) * (NBRE_PREMIER_2 - 1), E);
    int message_decode = exp_modulaire(i, cle_secrete, cle_publique);

    //message_decode /= 256;
    // conversion int to string
    char s = static_cast<char>(message_decode);

    fichier_out << message_decode;
}

int main(){
    // création de la clé publique
    int cle_publique = NBRE_PREMIER_1 * NBRE_PREMIER_2;

    // inscripion de message
    string message_original;
    getline(cin, message_original, '\0');
    
    // découpage du message en groupes de 3 octets (24 bits) et codage de ces derniers
    string message_coupe;
    fichier_out.open("secret.txt");
    for (size_t i = 0; i < message_original.size(); i += 3) {
        message_coupe = message_original.substr(i, 1);

        for_each(message_coupe.begin(), message_coupe.end(), code_char);
    }
    for_each(message_coupe.begin(), message_coupe.end(), code_char);
    fichier_out.close();

    // décodage du message
    string message_code;
    fichier_in.open("secret.txt");
    fichier_in >> message_code;
    fichier_in.close();

    fichier_out.open("out.txt");
    for (size_t i = 0; i < message_code.size(); i += 5) {
        message_coupe = message_code.substr(i, 9);

        for_each(message_coupe.begin(), message_coupe.end(), decode_char);
    }
    fichier_out.close();
}