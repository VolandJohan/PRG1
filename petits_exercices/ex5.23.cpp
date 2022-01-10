#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool est_impair(int a) {
    return a % 2;
}

int main() {
    vector<int> v{2, 3, 4, 5, 7, 11};
    int tab[] = {1, 3, 3};

    cout << "Vecteur impair ? : " << all_of(v.begin(), v.end(), est_impair) << endl;
    cout << "Tableau impair ? : " << all_of(tab, tab + 3, est_impair) << endl;
}