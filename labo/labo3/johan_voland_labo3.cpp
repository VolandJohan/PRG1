#include <iostream>

/*	file : johan_voland_labo3.cpp
	brief : transformation d'une durée en secondes vers des semaines, jours, heures, minutes et secondes
	author : Johan Voland
	date : 22.09.2021 */

using namespace std;

const int SECONDES_PAR_SEMAINE = 7*24*60*60;
const int SECONDES_PAR_JOUR = 24*60*60;
const int SECONDES_PAR_HEURE = 60*60;
const int SECONDES_PAR_MINUTE = 60;

int main()
{
	int duree;
	cout << "Duree en secondes a convertir : " << endl;
	cin >> duree;

	/* Calcul des divers temps */
	int semaine = duree/SECONDES_PAR_SEMAINE;
	
	duree = duree%SECONDES_PAR_SEMAINE;
	int jour = duree/SECONDES_PAR_JOUR;
	
	duree = duree%SECONDES_PAR_JOUR;
	int heure = duree/SECONDES_PAR_HEURE;

	duree = duree%SECONDES_PAR_HEURE;
	int minute = duree/SECONDES_PAR_MINUTE;
	
	duree = duree%60;
	int seconde = duree;
  
	cout << int(duree) << "s = " << semaine << " semaines, " 
		<< jour << " jours, "
		<< heure << " heures, "
		<< minute << " minutes, "
		<< seconde << " secondes.";
}