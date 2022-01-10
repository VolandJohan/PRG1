/*
    file    : johan_voland_labo28.cpp
    brief   : Créer une classe permettant de stocker, trier et compter le nombre de mots d'un texte.
    author  : Johan Voland
    date    : 10.12.2021
*/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Stocke un mot sous forme d'une chaîne de caractères
 *        ainsi que son nombre d'occurences.
 * 
 */
class Mot {
    private :
        string texte;
        void trier_mots(vector<string>& chaine_caracteres);
    public :
        Mot(string texte);
        vector<string> mots_dans_vecteur();
        void afficher_lexique(/*vector<string>& chaine_caracteres*/);
};

Mot::Mot(string texte) : texte(texte) {};

/**
 * @brief Extrait chaque mot d'un texte à l'inscrit dans un vecteur.
 * 
 * @param texte texte à découper
 * @return vector<char> vecteur contenant les mots
 */
vector<string> Mot::mots_dans_vecteur() {
    vector<string> v;

    size_t prev = 0, pos;
    while((pos = texte.find_first_of(" ,';.\n?!-()+–—…\x99\xC5:", prev)) != string::npos) {
        if (pos > prev) {
            v.push_back(texte.substr(prev, pos - prev));
        }
        prev = pos + 1;
    }
    if (prev < texte.length()) {
        v.push_back(texte.substr(prev, string::npos));
    }

    trier_mots(v);

    return v;
}

/**
 * @brief Trie les mots d'un vecteur par ordre décroissant.
 * 
 * @param chaine_caracteres vecteur contenant les mots
 */
void Mot::trier_mots(vector<string>& chaine_caracteres) {
    sort(chaine_caracteres.rbegin(), chaine_caracteres.rend());
}

/**
 * @brief Compte et affiche le nombre de mots contenus dans vecteur.
 * 
 */
void Mot::afficher_lexique() {
    vector<string> chaine_caracteres = mots_dans_vecteur();
    int compteur = 1;
    string prev = chaine_caracteres.at(0);

    // parcours les éléments du vector
    for (size_t i = 0; i < chaine_caracteres.size(); ++i){
        // incrémentation du compteur si le mot est identique au preview
        if(chaine_caracteres.at(i) == prev) {
            ++compteur;
        } else { // sinon affiche le nombre d'occurences, change le preview et reset le compteur
            cout << prev << " : " << compteur << endl;
            prev = chaine_caracteres.at(i);
            compteur = 1;
        }
    }
}

int main() {
    string input;
    getline(cin, input, '\0');

    Mot texte = input;
    texte.mots_dans_vecteur();
    texte.afficher_lexique();
}