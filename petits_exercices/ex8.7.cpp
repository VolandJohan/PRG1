#include <iostream>
using namespace std;

template <typename T, size_t n> class Array;

// On peut programmer la fonction ici où juste l'annoncer.
template <typename T, size_t n>
ostream& operator<<(ostream& os, const Array<T, n>& cv)/* {
    //return os << cv.tab[n];
    cout << "[";
    for ( size_t i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << cv.tab[i];
    }
    cout << "]";
}*/;

template <typename T, size_t n> class Array {
public:
    Array(const T& valeur);

    friend ostream& operator<< <T, n>(ostream& os, const Array<T, n>& cv);

private:
    T tab[n];
};

/* Implémenter constructeur. */
template <typename T, size_t n>
Array<T, n>::Array(const T& valeur) {
    for (T& e : tab) { e = valeur; }
}

/* Implémenter opérateur <<. */
template <typename T, size_t n>
ostream& operator<<(ostream& os, const Array<T, n>& cv) {
    //return os << cv.tab[n];
    os << "[";
    for ( size_t i = 0; i < n; ++i) {
        if (i > 0) {
            os << ", ";
        }
        os << cv.tab[i];
    }
    os << "]";

    return os;
};

int main() {
    Array<int, 3> a1(1);
    cout << a1 << endl;
    Array<double, 4> a2(1.5);
    cout << a2 << endl;
    
    return EXIT_SUCCESS;
}