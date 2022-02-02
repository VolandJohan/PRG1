/**
 * Exercice 1
 * @brief Surcharge de fonctions génériques.
 * 
 */
/*#include <iostream>
using namespace std;

template<typename T, typename U> int f(T, U) {return 1;}
template<typename T> int f(T, T) {return 2;}
template<typename T> int f(int, T) {return 3;}
template<typename T> int f(T, short) {return 4;}
template<typename T> int f(int, short) {return 5;}

int main() {
    char c; short s; int i; float x;

    cout << f(x, i) << endl;
    cout << "f(i, i) est ambigu" << endl;
    cout << f(s, i) << endl;
    cout << f(c, c) << endl;
    cout << f(x, s) << endl;
    cout << "f(i, s) est ambigu" << endl;
    cout << f(c, s) << endl;
    cout << f(x, x) << endl;
    cout << f(i, x) << endl;
    cout << f(s, x) << endl;
    cout << f(c, x) << endl;
}*/

/**
 * Exercice 2
 * @brief Constructeurs, affectation et destructeur.
 * 
 */
#include <iostream>
#include <array>
using namespace std;

class C {
    double data;
 public :
    C():data(1.0) {cout << "1 ";}
    C(double val):data(val) {cout << "2 ";}
    C(C const& c):data(c.data * 3) {cout << "3 ";}
    C& operator=(C const& c) {cout << "4 "; data = c.data; return *this;}
    ~C();
};

int main() {
    {
        C c;
        c = 5.0;
        cout << "x ";
    }
    cout << endl;

    {
        C c(6.0);
        const C d = c;
        cout << "x ";
    }
    cout << endl;

    {
        C c[2];
        c[0] = C(7.0);
        cout << "x ";
    }
    cout << endl;

    {
        C c(8.0);
        {
            C d(9.0);
            d = c;
            cout << "x ";
        }
        cout << "x ";
    }
    cout << endl;

    {
        array<C, 3> a {{ C(10.0), C(11.0), C(12.0) }};
        a[2] = a[0];
        cout << "x ";
    }
    cout << endl;
}