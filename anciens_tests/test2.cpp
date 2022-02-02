/**
 * Exercice 1
 * @brief Indiquer ce que va afficher le programme.
 * 
 */
/*
#include <iostream>
using namespace std;

void f(float a, const int& b) {cout << a << " " << b << endl;}
void f(float a, int& b) {cout << a << " "  << 2*b << endl;}
void f(char a, long b) {cout << a << " " << 3*b << endl;}
void f(int a, double b) {cout << a << " " << 4*b << endl;}
void f(float a, char b, int c=0) {cout << a << " " << 5*b << " " << c << endl;}
void f(char a, int& b, float c) {cout << a << " " << 6*b << " " << c << endl;}

int main() {
    bool b = false;
    char c = '\11';
    short s = 1;
    long p = 5;
    int n = 4;
    float x = 8;
    double y = 10;

    f(x, n);
    f(x, c);
    f(b, x);
    f(p, c);
    f(s, y);
    f(y, n);
    f(c, c, x);
    f(c, n, y);
}*/

/**
 * Exercice 2
 * @brief Indiquer ce que va afficher le programme.
 * 
 */
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    {
        const size_t N = 4;
        int t[] = {1, 2, 4, 8};
        for (size_t i = N; i > 1; i -= 2)
            t[i - 2] += t[i - 1];
        for (size_t i = 0; i < N; i++) cout << t[i] << " "; cout << endl;
    }
    {
        const size_t N = 6;
        array<int, N> a;
        auto it1 = a.end() - 5,
             it2 = a.begin() + 3;
        a.fill(11);
        fill (it1, it2, a.empty());
        for (int e : a) cout << e << " "; cout << endl;
    }
    {
        const size_t N = 5;
        int t[] = {1, 2, 4, 8, 3};
        for (size_t i = N; i > 0; --i) {
            t[i - 1] = t[N - i]++;
        }
        for (size_t i = 0; i < N; i++) cout << t[i] << " "; cout << endl;
    }
    {
        vector<int> v = {2, 4, 8};
        v.resize(5, 10);
        v.insert(v.end() - 2, v.rbegin() + 1, v.rend() - 1);
        for (int i : v) cout << i << " "; cout << endl;
    }
    {
        const size_t N = 3;
        vector<size_t> v = {3};
        for (size_t i = 0; i < N; ++i)
            v.push_back(v.front() * v.back() + v.size());
        v.pop_back();
        for (size_t i : v) cout << i << " "; cout << endl;
    }
    {
        vector<int> v{2, 4, 8, 10};
        vector<int> w(6);
        copy(v.begin(), v.end(), w.rbegin());
        for (int e : w) cout << e << " "; cout << endl;
    }
    {
        vector<int> v = {-2, -4, -3, 5, 8, 2};
        auto it1 = ++min_element(v.begin(), v.end()),
             it2 = --max_element(v.begin(), v.end());
        v.erase(it1, it2);
        for (int i : v) cout << i << " "; cout << endl;
    }
    {
        vector<int> v = {2, 4, 8, 10};
        for (int val : v)
            val += val;
        for (int i : v) cout << i << " "; cout << endl;
    }
    {
        vector<int> v{2, 4, 4, 8, 8, 4, 4, 4, 2};
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int e : v) cout << e << " "; cout << endl;
    }
    {
        vector<int> v{2, 4, 8, 10, 11};
        vector<int> w{4, 1, 2, 3, 5};
        for (auto i = w.rbegin(); i != w.rend(); ++i)
            if (2**i < v.at((size_t)*i - 1))
                v.at((size_t)*i - 1) *= *i;
        for (int e : v) cout << e << " "; cout << endl;
    }
    {
        vector<int> v{4, 3, 1, 6, 8, 2};
        auto i1 = min_element(v.begin(), v.end());
        auto i2 = max_element(v.begin(), v.end());
        *i2 = 6;
        fill(i1, i2, 2);
        for (int e : v) cout << e << " "; cout << endl;
    }
}

/**
 * Exercice 3
 * @brief Que va afficher le programme.
 * 
 */
/*#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int g(int a, int b) { return a / b; }
int h(int n) { return n % 4 -1; }

int main() {
    {
        vector<int> v{2, 3, 5, 9, 7};
        cout << accumulate(v.begin(), v.end(), 4, g) << endl;
    }
    {
        vector<int> w1{1, 2, 4, 3, 6, 8};
        vector<int> w2{2, 3, 5, 9};
        w1.insert(w1.end(), w2.back());
        vector<int> v(w1.size());
        v.erase(remove_copy_if(w1.begin(), w1.end(), v.begin(), h), v.end());
        for (int e : v) cout << e << " "; cout << endl;
    }
    {
        vector<int> v{2, 4, 5, 8, 7};
        v.reserve(8);
        vector<int> w(v.capacity());
        transform(v.begin(), v.end(), w.rbegin(), h);
        for (int e : w) cout << e << " "; cout << endl;
    }
    {
        string str = "programmation";
        string s = str.substr(str.find_first_not_of("prog"), 4);
        cout << s << endl;
    }
    {
        string str("programmation", 5);
        string s(string(str, 3) + str);
        cout << s << endl;
    }
}*/

/**
 * Exercice 4
 * @brief Afficher la médiane d'un tableau.
 * 
 */
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double calcul_mediane(vector<int> v) {
    sort(v.begin(), v.end());
    if (v.size() == 0) {
        return 0;
    }
    if (v.size() % 2 != 0) {
        return v.at(v.size() / 2);
    } else {
        int valeur;
        valeur = v.at(v.size() / 2) + v.at(v.size() / 2 - 1);
        return valeur / 2;
    }
}

int main() {
    vector<int> v;
    int valeur;
    cout << "Entrez un nombre : " << endl;
    while (cin >> valeur) {
        cout << "Entrez un nombre : " << endl;
        v.push_back(valeur);
    }
    int mediane = calcul_mediane(v);
    cout << "La mediane vaut : " << mediane << endl;
}*/