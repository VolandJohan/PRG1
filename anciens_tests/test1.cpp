#include <iostream>
#include <iomanip>
using namespace std;

/**
 * Exercice 1
 * @brief Déterminer si identificateurs valides.
 * 
 */
/*
int _bronze;    OUI
int Argent;     OUI
int or;         Non, c'est un nom déjà réservé
int 2jambes;    Non, on ne peut pas commencer avec un nombre
int une_tête;   Non, il y a un caractère spécial
int main;       OUI
*/

/**
 * Exercice 2
 * @brief Déterminer type et valeur d'expressions.
 * 
 */
/*
int main() {

    int i = 5;
    unsigned u = 4;
    char c = 'C';
    double d = 5.7, e = 2.2;
    uint8_t f;

    cout << "(short)e - (short)d = " << (short)e - (short)d << endl;
    cout << "(short)d - (unsigned)e = " << (short)d - (unsigned)e << endl;
    cout << "4/3*3.14 = " << 4/3*3.14 << endl;
    bool result = u - i < 0;
    cout << "u - i < 0 = " << result << endl;
    cout << "(char)(c-- + d) = " << (char)(c-- + d) << endl;
    int result2 = i > u ? u : d;
    cout << "i > u ? u : d = " << result2 << endl;
    cout << "(int)e * ++d" << (int)e * ++d << endl;
    int result3 = 7 > 6 ? 5 > 4 ? 3 : 2 : 1;
    cout << "7 > 6 ? 5 > 4 ? 3 : 2 : 1 = " << result3 << endl;
    f = 258;
    cout << "f = 258 = " << f << endl;
}*/


/**
 * Exercice 3
 * @brief Qu'affichent les codes suivants ?
 * 
 */
int main() {
    {
        cout << "Question 1 :" << endl;
        cout << 011      << " "
             << 0b11 << " "
             << 0x11 << " "
             << 110;
    }
    {
        cout << "Question 2 :" << endl;
        int i = 2;
        {
            float i = 2.2;
            cout << i;
            {
                char i = 'i';
                cout << i;
            }
            cout << i;
        }
        cout << i;
    }

    {
        cout << "Question 3 :" << endl;
        int a = 0;
        if (a =! 2)
            cout << "a different de 2";
        else
            cout << "a vaut 2: " << a;
    }
    
    {
        cout << "Question 4 :" << endl;
        cout << setprecision(4) << 3.14159;
    }

    {
        cout << "Question 5 :" << endl;
        cout << fixed << setprecision(4) << 3.14159;
    }

    {
        cout << "Question 6 :" << endl;
        cout << boolalpha << (2 < 2 == 0) ;
    }

    {
        cout << "Question 7:" << endl;
        int i = 13, j = 0;
        while (i > j++)
            i /= 2; j++;
        cout << i << " " << j;
    }

    {
        cout << "Question 8:" << endl;
        int i = -2, j = 3;
        do {
            j--;
        } while (j += i++);
        cout << i << " " << j;
    }
}

/**
 * Exercice 5
 * @brief Afficher plus petit diviseur commun > 1.
 * 
 */
/*#include <iostream>
using namespace std;
int main() {
    cout << "Entrez un nombre : " << endl;
    int valeur;
    cin >> valeur;
    int diviseur = 2;
    while ((valeur % 2) != 0) {
        ++diviseur;
    }
    cout << diviseur << " est le plus petit diviseur." << endl;
}*/