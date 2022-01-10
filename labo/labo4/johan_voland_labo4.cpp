#include <iostream>
#include <limits>

/* 	file : johan_voland_labo4.cpp
	brief : détermine et affiche la taille en bits et l'intervalle de tous les types numériques.
	author : Johan Voland
	date : 28.09.2021	*/
	
using namespace std;

int main () {
		
	/* types entiers signés */
	// le char est converi en int sinon un caractère est affiché à la place d'un nombre
	cout << "signed char (" << sizeof(char)*8 << " bits) : " << (int) numeric_limits<char>::lowest() << " . . " << (int) numeric_limits<char>::max() << endl
		<< "signed short (" << sizeof(short)*8 << " bits) : " << numeric_limits<short>::lowest() << " . . " << numeric_limits<short>::max() << endl
		<< "signed int (" << sizeof(int)*8 << " bits) : " << numeric_limits<int>::lowest() << " . . " << numeric_limits<int>::max() << endl
		<< "signed long (" << sizeof(long)*8 << " bits) : " << numeric_limits<long>::lowest() << " . . " << numeric_limits<long>::max() << endl
		<< "signed long long (" << sizeof(long long)*8 << " bits) :" << numeric_limits<long long>::lowest() << " . . " << numeric_limits<long long>::max() << endl
		
	/* types entiers non signés */
		<< "unsigned char (" << sizeof(unsigned char)*8 << " bits) :" << (int) numeric_limits<unsigned char>::lowest() << " . . " << (int) numeric_limits<unsigned char>::max() << endl
		<< "unsigned short (" << sizeof(unsigned short)*8 << " bits) : " << numeric_limits<unsigned short>::lowest() << " . . " << numeric_limits<unsigned short>::max() << endl
		<< "unsigned int (" << sizeof(unsigned int)*8 << " bits) : " << numeric_limits<unsigned int>::lowest() << " . . " << numeric_limits<unsigned int>::max() << endl
		<< "unsigned long (" << sizeof(unsigned long)*8 << " bits) : " << numeric_limits<unsigned long>::lowest() << " . . " << numeric_limits<unsigned long>::max() << endl
		<< "unsigned long long (" << sizeof(unsigned long long)*8 << " bits) : " << numeric_limits<unsigned long long>::lowest() << " . . " << numeric_limits<unsigned long long>::max() << endl
	
	/* types réels */
		<< "float (" << sizeof(float)*8 << " bits) : " << numeric_limits<float>::lowest() << " . . " << numeric_limits<float>::max() << endl
		<< "double (" << sizeof(double)*8 << " bits) : " << numeric_limits<double>::lowest() << " . . " << numeric_limits<double>::max() << endl
		<< "long double (" << sizeof(long double)*8 << " bits) : " << numeric_limits<long double>::lowest() << " . . " << numeric_limits<long double>::max();
}