#include <iostream>
#include <vector>

using namespace std;

void afficher_vector (const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// le const & est utilisé si on ne touche pas au vecteur
vector<int> concatenation_vecteurs (/*const vector<int>& v1*/vector<int> v1, const vector<int>& v2) {
    /*vector<int> resultat (v1.size() + v2.size());
    for (size_t i = 0; i < v1.size(); ++i) {
        resultat[i] = v1[i];
    }
    for (size_t i = 0; i < v2.size(); ++i) {
        resultat[i + v1.size()] = v2[i];
    }
    return resultat;*/
    for (size_t i = 0; i < v2.size(); ++i) {
        v1.push_back(v2[i]);
    }
    return v1;
}

int main() {
    afficher_vector(concatenation_vecteurs({1, 3}, {2, 4, 5}));
}