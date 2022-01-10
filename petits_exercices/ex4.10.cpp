#include <iostream>

using namespace std;

bool operation(double n1, double n2, char operateur, double& resultat){
    switch (operateur) {
        case '+':
            resultat = n1 + n2;
            return true;
        case '-':
            resultat = n1 - n2;
            return true;
        case '*':
            resultat = n1 * n2;
            return true;
        case '/':
            resultat = n1 / n2;
            return true;
        default :
            return false;
    }
}

int main(){
    cout << "Entrez deux valeurs : ";
    int n1, n2;
    cin >> n1 >> n2;
    cout << "Entrez l'operateur : ";
    char operateur;
    cin >> operateur;

    double resultat;
    if (operation(n1, n2, operateur, resultat)){
        cout << resultat;
    } else {
        cout << "Operateur " << operateur << " invalide.";
    }
}