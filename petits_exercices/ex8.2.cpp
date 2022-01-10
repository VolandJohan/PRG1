#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T> void compter (const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "L'element " << v.at(i) << " apparait :" 
        << count(v.begin(), v.end(), v.at(i)) << " fois." << endl;
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 4};
    compter(v);
}