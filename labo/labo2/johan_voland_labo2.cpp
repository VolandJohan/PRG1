#include <string>
#include <iostream>

// file : johan_voland_labo2.cpp
// author : Johan Voland
// date : 22.09.2021

using namespace std;

const int ANNEE_ACTUELLE = 2021;

int main() {
	string prenom;
	int age;
	int annee_naissance;
	
	// prendre prenom
	cout << "Entrez votre pr\x82nom : ";
	getline(cin, prenom);
	
	// prendre age
	cout << "Entrez votre \x83ge : ";
	cin >> age;
	
	// année de naissance
	annee_naissance = ANNEE_ACTUELLE - age;
	
	// affichage
	cout << "Bonjour " << prenom << ",\n" << "vous avez " << age << " ans et vous \x88tes n\x82(e) en " << annee_naissance << ".";
}