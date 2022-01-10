#include <iostream>

/*	file : johan_voland_labo5.cpp
	brief : calcul de l'heure d'une horloge en fonction de l'angle de l'aiguille.
	author : Johan Voland
	date : 29.09.2021 */
	
using namespace std;

const int MINUTES_PAR_DEGRE = 2;
const int MINUTES_PAR_HEURE = 60;
const int HEURES_MAX = 12;

int main(){
	
	int angle;
	
	cout << "Entrez l'angle (en degres) :" << endl;
	cin >> angle;
	
	angle %= 360;	// pour toujour avoir un angle <= à 360
	int minutes = MINUTES_PAR_DEGRE * (90 - angle);
	
	/* conversions des durées */
	int heure = minutes / MINUTES_PAR_HEURE;
	// transforme les heures négatives ou à 0 en heures correctes 
	heure = (heure + HEURES_MAX - 1) % HEURES_MAX + 1;
	minutes = minutes % MINUTES_PAR_HEURE;
	
	cout << angle << " degres = " << heure << " h " << minutes << endl;
	
}