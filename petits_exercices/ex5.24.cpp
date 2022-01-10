#include <iostream>
#include <vector>
#include <algorithm>

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

vector<int> concatenation_vecteurs (vector<int> v1, const vector<int>& v2) {
    for (size_t i = 0; i < v2.size(); ++i) {
        v1.push_back(v2[i]);
    }
    return v1;
}

int main() {
    //afficher_vector(concatenation_vecteurs({1, 3}, {2, 4, 5}));
    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 6};
}