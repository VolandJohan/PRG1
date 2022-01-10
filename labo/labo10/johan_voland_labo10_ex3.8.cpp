/*
    file : johan_voland_labo10_ex3.8.cpp
    brief : L'utilisateur peut entrer le numéro d'un mois et le programme affiche le nombre de jours de ce dernier.
    author : Johan Voland
    date : 12.10.2021
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // entrée des données
    cout << "Entrez un numero de mois (1-12) : " << endl;
    int numero_mois;
    cin >> numero_mois;

    /* -- On vérifie d'abord le numéro du moi entrée -- */
    // si le mois entré = 2 alors on est en février
    bool his_feb = numero_mois == 2 ? true : false;
    // si le mois entré <= 7 alors les mois impairs font 31 jours
    bool range_mois = numero_mois <= 7 ? false : true;
    // si le modulo du mois est différent de 0 alors le mois entré en impair
    bool mois_pair = (numero_mois %= 2) != 0 ? false : true;

    /* -- On utilise les vérifications pour faire varier l'affichage --*/
    /*  si le mois est <= 7 alors les mois impair on 31 jours
        si le mois est > 7 alors les mois pairs on 31 jours */
    string nbre_de_jour = range_mois ? numero_mois ? "30" : "31" : numero_mois ? "31" : "30";
    // si c'est le mois de février on donne un affichage différent
    nbre_de_jour = his_feb ? "28 ou 29" : nbre_de_jour;

    cout << "Ce mois a " << nbre_de_jour << " jours";
}