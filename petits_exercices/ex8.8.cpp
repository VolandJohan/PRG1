#include <iostream>
using namespace std;

template <typename T, size_t n> class Array;

template <typename T, size_t n>
ostream& operator<<(ostream& os, const Array<T, n>& cv);

template <size_t n>
ostream& operator<<(ostream& os, const Array<bool, n>& cv);

template <typename T, size_t n> class Array {
public:
    Array(const T& valeur);

    /* opérateurs d'affichage */
    friend ostream& operator<< <T, n>(ostream& os, const Array<T, n>& cv);
    friend ostream& operator<< <n>(ostream& os, const Array<bool, n>& cv);

private:
    T tab[n];
};

/* implémenter constructeur */
template <typename T, size_t n>
Array<T, n>::Array(const T& valeur) {
    for (T& e : tab) { e = valeur; }
}

/* implémenter opérateurs << */
template <typename T, size_t n>
ostream& operator<<(ostream& os, const Array<T, n>& cv) {
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

template <size_t n>
ostream& operator<<(ostream& os, const Array<bool, n>& cv) {
    os << "[";
    for ( size_t i = 0; i < n; ++i) {
        if (i > 0) {
            os << ", ";
        }
        if (cv.tab[i]) {
            os << "true";
        } else {
            os << "false";
        }
    }
    os << "]";

    return os;
};

int main() {
    Array<int, 3> a1(1);
    cout << a1 << endl;
    
    Array<double, 4> a2(1.5);
    cout << a2 << endl;
    
    Array<bool, 5> a3(true);
    cout << a3 << endl;
    
    return EXIT_SUCCESS;
}