/*
    file : johan_voland_labo26.cpp
    brief : Insérer un texte dans une variable. Il faut ensuite extraire et trier chaque mot.
    author : Johan Voland
    date : 30.11.2021
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief extrait chaque mot du texte et les inscrits dans un vecteur
 * 
 * @param texte texte à utiliser
 * @return vector<string> vecteur contenant chaque mot du texte
 */
vector<string> texte_dans_vecteur(string texte) {
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

    return v;
}

/**
 * @brief affiche le contenu d'un vecteur
 * 
 * @param v vecteur contenant les informations
 */
void afficher_vecteur(const vector<string>& v) {
    for (auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }
}

/**
 * @brief compte le nombre de mots apparaissant à plusieur reprises dans un string 
 * 
 * @param v vector contenant le texte 
 */
void count_repeated_words(vector<string>& v) {
    int compteur = 1;
    string prev = v.at(0);

    // parcours les éléments du vector
    for (size_t i = 0; i < v.size(); ++i){
        // incrémentation du compteur si le mot est identique au preview
        if(v.at(i) == prev) {
            ++compteur;
        } else { // sinon affiche le nombre d'occurences, change le preview et reset le compteur
            cout << prev << " : " << compteur << endl;
            prev = v.at(i);
            compteur = 1;
        }
    }
}

int main() {
    string texte;
    // permet de prendre l'entièreté du texte, le \0 fait que je m'arrète à la fin du texte
    getline(cin, texte, '\0');
    

    vector<string> v = texte_dans_vecteur(texte);
    
    sort(v.begin(), v.end());
    count_repeated_words(v);
}