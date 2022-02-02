#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void afficher_vector(vector<int> v) {
	cout << "[";
	for (size_t i = 0; i < v.size(); ++i) {
		cout << v.at(i);
		if (i != v.back())
			cout << ", ";
	}
	cout << "]" << endl;
}

int somme(vector<int> v){
	int somme = 0;
	for (size_t i = 0; i < v.size(); ++i){
		somme += v.at(i);
	}
	return somme;
}

bool est_impaire(int i) {
	return i % 2;
}

int main()
{
	/* initialiser les tableaux */
	int tab[] = {3, 2, -5, 2, 4};
	size_t taille_tab = sizeof(tab) / sizeof(int);
	vector<int> v;
	// remplir vecteur v
	for (size_t i = 0; i < taille_tab; ++i)
		v.push_back(tab[i]);
	
	
	
	/* affichage du vecteur initial */
	cout << "Le vecteur v initial :" << endl;
	afficher_vector(v);
	
	/* valeurs les plus grandes/petites */
	auto it = min_element(v.begin(), v.end());
	cout << "La plus petite valeur de v : " << *it << endl;
	it = max_element(v.begin(), v.end());
	cout << "La plus grande valeur de v : " << *it << endl;
	
	cout << "La somme des elements de v : " << somme(v) << endl;
	
	cout << "Nombre d'occurrences de la valeur 2 dans v : " << count(v.begin(), v.end(), 2) << endl;
	cout << "Nombre de valeurs impaires dans v : " << count_if(v.begin(), v.end(), est_impaire) << endl;
	
	/* trier vecteur */
	sort(v.begin(), v.end());
	cout << "Le vecteur v trie croissant :" << endl;
	afficher_vector(v);
	reverse(v.begin(), v.end());
	cout << "Le vecteur v trie decroissant :" << endl;
	afficher_vector(v);
}