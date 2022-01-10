#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Ligne;
typedef vector<Ligne> Matrice;

void somme_diagonales(Matrice m, int& diago_descendante, int& diago_ascendante) {
    size_t nombre_lignes = m.size();
    diago_descendante = diago_ascendante = 0;
    for (size_t i = 0; i < nombre_lignes; ++i) {
        diago_descendante += m.at(i).at(1);
        diago_ascendante += m.at(i).at(nombre_lignes - 1 - i);
    }
}

int main() {
    Matrice m = {{1, 0, 1}, {0, 1, 0}, {1, 1, 0}};
    int desc, asc;
    somme_diagonales(m, desc, asc);
    cout << desc << " " << asc << endl;
}