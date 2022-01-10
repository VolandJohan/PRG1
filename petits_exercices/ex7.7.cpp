#include <iostream>

using namespace std;

class C {
	int x;
public:
	// constructeurs
	C():x(0){};
	C(int valeur) : x(valeur) {};

	friend ostream& operator<<(ostream& os, const C& variable) {
        os << variable.x;
        return os;
    }

    /***** Opérateurs logiques *****/
    friend bool operator==(const C& left, const C& right) {
        return left.x == right.x;
    }
    /***** alternative pour que ce soit un membre de la classe *****
    bool operator==(const C& right) const {
        return x == right.x;
    }*/
    friend bool operator!=(const C& left, const C& right) {
        return !(left == right);
    }
    /***** alternative pour que ce soit un membre de la classe *****
    bool operator!=(const C& right) const {
        return !(*this == right);
    }*/

    /***** Opérateur ++ *****/
    // opérateur préfixe
    C& operator++() {
        ++x;
        return *this; // faire référence à la variable privée
    }
    // opérateur postfixe
    C operator++(int) { // le paramètre permet de faire la différences entre les 2 ++
        C tmp = *this;
        ++(*this); // pour gérer la différence de priorité avec l'autre ++
        return tmp;
    }

    /***** Opérateurs arithmétiques *****/
    C& operator+=(const C& right) {
        x += right.x;
        return *this;
    }
    friend C operator+(C left, const C& right) {
        left += right;
        return left;
    }
};

int main() {
    C c0, c1(1), c2 = 5;
    const C C3{7};

    cout << c0 << endl
         << c1 << endl;
    
    cout << boolalpha;
    cout << (c0 == c1) << endl;
    cout << (c0 != c1) << endl;
    cout << noboolalpha;

    cout << c1++ << endl; 
    cout << c1 << endl; 
    cout << ++c1 << endl;

    cout << c1 + c2 << endl; 
    c1 += c2; 
    cout << c1 << endl; 
    cout << C3 + c2 << endl;

    return EXIT_SUCCESS;
}