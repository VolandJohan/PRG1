#include "Uint.hpp"
#include <iostream>
#include <string>
#include <random>

using namespace std;

/**
 * @brief Génère un nombre aléatoire entre 0 et un nombre entré.
 * 
 * @param nb Nombre final.
 * @return Uint Nombre aléatoire entre 0 et nb.
 */
Uint gen_random(size_t nb) {
  return rand() & nb;
}

/**
 * @brief Calcul l'exponentielle modulaire d'un nombre.
 * 
 * @param base 
 * @param exponentiel 
 * @param modulo 
 * @return Uint 
 */
Uint expModulaire (Uint base, Uint exponentiel, Uint modulo){
    Uint result = 1;
    while (exponentiel > 0) {
        if (exponentiel % 2 == 0) {
            base = (base*base) % modulo;
            exponentiel /= 2;
        } else {
            result = result * base % modulo;
            exponentiel -= 1;
        }
    }
    return result;
}

/**
 * @brief Vérifie qu'un nombre est premier.
 * 
 * @param nbre Nombre à vérifier.
 * @return true
 * @return false 
 */
bool prime(Uint nbre) {
    if (nbre < 2) {
        return false;
    }
    if (nbre == 2) {
        return true;
    }

    for (int i = 0; i < 10; ++i) {
        // nombre aléatoire
        Uint a = rand() % (nbre - 1) + 1;

        if (expModulaire(a, nbre - 1, nbre) != 1) {
            return false;
        }

        Uint q = 1;
        Uint u = nbre - 1;

        while (u%2 == 0 && q == 1) {
            u /= 2;
            q = expModulaire(a, u, nbre);

            if (q != 1 && q != nbre - 1) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
  string nombre;
  cout << "Introduire un nombre entier: ";
  cin >> nombre;
  size_t nb = stoul(nombre);
  Uint n;           // Vérification constructeur vide   
  n = Uint(nombre); // Vérification constructeur par string
  
  cout << "Nombre lu " << n << endl; // Vérification opérateur <<

  Uint factorielle(1); // Vérification constructeur par entier (explicite)
  cout << factorielle << endl;
  for (size_t i = 2; i <= nb; ++i)
  {
    factorielle *= i; // Vérification *= size_t
    cout << i << "! = " << factorielle << endl;
  }

  factorielle = 1; // Vérification constructeur par entier implicite
  for (Uint i = 2; i <= n; ++i) // Vérification <= et ++
  {
    factorielle *= i; // Vérification *= Uint
    cout << i << "! = " << factorielle << endl;
  }

  Uint fibo_m2(0), fibo_m1(1), fibonacci;
  for (Uint i = 2; i <= n; ++i) 
  {
    fibonacci = fibo_m2 + fibo_m1; // Vérification Uint + Uint
    cout << "fibonacci(" << i << ") = " << fibonacci << endl;
    fibo_m2 = fibo_m1;
    fibo_m1 = fibonacci;
  }

  // Vérification -, > et -=
  for (Uint i = n - 2; i > 0; i -= 1) 
  {
    cout << "fibonacci(" << i << ") = " << fibo_m2 << endl;
    fibonacci = fibo_m1;
    fibo_m1 = fibo_m2;
    fibo_m2 = fibonacci - fibo_m2; // Vérification -
  }

  for (Uint i = n; i > 0; i -= 1)
  { 
    cout << i << "! = " << factorielle << endl;
    factorielle = factorielle / i; // Vérification Uint/Uint
  }
    
  Uint p;
  do
  { 
    p = gen_random(nb); // Vérification gen_random
    cout << p << endl;
  } while (!prime(p));  // Vérification exponentiation modulaire, prime
}

