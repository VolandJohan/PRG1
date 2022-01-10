#include <iostream>

/*
	file : johan_voland_labo6.cpp
	brief : Calcul de la durée d'un trajet en fonction des heures.
	author : Johan Voland
	date : 01.10.2021
*/

using namespace std;

const int MINUTES_PAR_HEURES = 60;
const int MINUTES_PAR_JOURS = 1440;

int main()
{
	int heure_depart;
	int minutes_depart;
	int heure_arrivee;
	int minutes_arrivee;
	
	/* Entrée des données */
	cout << "Entez l'heure de depart : ";
	cin >> heure_depart;
	cout << "Entrez les minutes : ";
	cin >> minutes_depart;
	cout << "Entez l'heure d'arrivee : ";
	cin >> heure_arrivee;
	cout << "Entrez les minutes : ";
	cin >> minutes_arrivee;
	
	/* Conversion des heures en minutes */
	minutes_depart += heure_depart * MINUTES_PAR_HEURES;
	minutes_arrivee += heure_arrivee * MINUTES_PAR_HEURES;
	
	// calcul de la durée du voyage en minutes
	int duree_en_minutes = minutes_arrivee - minutes_depart;
	
	/*	le modulo et le + MINUTES_PAR_JOURS empêche d'avoir des minutes négatives
		le -1, +1 empêchent d'avoir 0 minutes */
	duree_en_minutes = (duree_en_minutes + MINUTES_PAR_JOURS -1) % MINUTES_PAR_JOURS + 1;
	
	// conversion des minutes en heures
	int duree_en_heures = duree_en_minutes / MINUTES_PAR_HEURES;	
	// calcul des minutes de l'heure
	duree_en_minutes %= MINUTES_PAR_HEURES;

	cout << endl << "Duree du trajet : " << duree_en_heures << "h" << duree_en_minutes << endl;
}