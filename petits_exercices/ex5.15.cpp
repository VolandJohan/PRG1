#include <iostream>
#include <vector>

using namespace std;

bool test_vector_impair(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << "vecteur impair : " << test_vector_impair({1, 1, 3}) << endl;
    cout << "vecteur pair : " << test_vector_impair({1, 2, 3}) << endl;
    cout << "vecteur vide : " << test_vector_impair({}) << endl;
}