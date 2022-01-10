/* Transformation en pouces et pieds d’une longueur exprimée en mètres*/
#include <iostream>

using namespace std;

const int POUCES_PAR_PIED = 12;
const double METRE_PAR_POUCE = 0.0254;

int main()
{
  double longueur; // Longueur entrée par l'utilisateur
  cout << "Longueur en metres a transformer en pieds et pouces: " << endl;
  cin >> longueur;
  
  /* arrondir la longueur en pouces uniquement*/
  int pouces = (int)(longueur/METRE_PAR_POUCE + 0.5);
  
  /* calculer le nombre de pieds */
  int pieds = pouces/POUCES_PAR_PIED;
  
  /* soustraire les pieds aux pouces */
  pouces = pouces % POUCES_PAR_PIED;
  
  /* Afficher le résultat */
  cout << pieds << " pieds et " 
       << pouces << " pouces " << "font " 
       << (pieds*POUCES_PAR_PIED + pouces)*METRE_PAR_POUCE << " metres"
       << endl;
}