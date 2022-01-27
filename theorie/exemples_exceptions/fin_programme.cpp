#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int n;

class A { // Pour mettre en évidence la destruction de variables
  double x;
public:
  A(double valeur): x(valeur){}
  ~A(){cout << "Destructeur " << "x = " << x << endl;}
};

void a() { cout << "a ";         exit(0);}  // sortie "propre", sans échec
void b() { A z(n); cout << "b "; exit(-1);} // sortie "propre", avec échec
void c() { cout << "c ";         abort();}  // sortie abrupte

void d() { cout << "d\n";}                  // Pour illuster atexit()
void e() { cout << "e ";}                   // idem

void f() { cout << "f\n";  terminate();}    // par défaut, appelle juste abort()
void g() { cout << "g " << flush;}          // vider explicitement le tampon
void h() { A z(n); cout << "h "; exit(3);}  // exit ne détruit pas z
void i() {static A y(-8.3); }               // exit détruit la var. globale y

void j() { cout << "j " << (n/0) << endl;}  // instruction illégale

void k() { char* c; cout << "k "; throw c;} // Exception de type char*
void l() { cout << "l ";          throw "Une exception de type const char*";}
void m() { cout << "m ";          throw "Une exception de type string"s;}
void p() {throw runtime_error("runtime error dans p");
         } // runtime_error est une sous-classe de exception

int main()
{
  atexit(d);    // empile la fonction d(), exécutée s'il y a un appel à exit()
  
  i();          // réserve de la place pour y, détruite par exit()
  
  cin >> n;
  
  A objet(n + 0.5); // Variable locale à main()
  
  if (n == 0)
    return 0;   // NB: EXIT_SUCCESS doit toujours valoir 0
                // Destructeur x = 0.5
                // Destructeur x = -8.3
                // d
                // aucun échec; code retourné par l'exécutable au système : 0
               
  atexit(e);    // empile e() par dessus d()
  
  if (n == 1)
    return 1;   // NB: EXIT_FAILURE vaut 1 avec g++
                // Destructeur x = 1.5
                // e Destructeur x = -8.3
                // d
                // échec; code de retour: 256 (linux; 1 avec g++ sous Windows)
                // tampons vidés, fichiers et connexions fermés, 
                // objets détruits
                
  if (n == 2)
    a();        // a e Destructeur x = -8.3
                // d 
                // code de retour: 0
                // objets locaux (automatiques) pas détruits
                
  if (n == 3)
    b();        // b e Destructeur x = -8.3
                // d 
                // code de retour: 65280 (-1 Windows)
                
  if (n == 4)
    c();        // 
                // Aborted (core dumped)
                // code de retour: 34304 (3 Windows)
                // Fin abrupte, tampons pas toujours vidés ("c" absent), etc.
                
  if (n == 5)
    f();        // f
                // terminate called without an active exception
                // Aborted (core dumped)   (message absent sous Windows)
                // code de retour: 34304

  set_terminate(g); // terminate() appelle g(), puis abort() au retour de g

  if (n == 6)
    f();        // f
                // g Aborted (core dumped)
                // code de retour: 34304
                
  set_terminate(h); // terminate() appellera h() qui termine "proprement"

  if (n == 7)
    f();        // f
                // h e Destructeur x = -8.3
                // d 
                // code de retour: 768 (3 sous Windows)

  if (n == 8)
    exit(2);    // e Destructeur x = -8.3
                // d 
                // code de retour: 512 (2 sous Windows)
               
  if (n == 9)
    j();        // Illegal instruction (core dumped)
                // code de retour: 33792 (-1073741795 sous Windows)
                
                
  if (n == 10)
    k();        // Exception pas récupérée, appel de terminate()
                // k h e Destructeur x = -8.3
                // d 
                // code de retour: 768 (3 sous Windows)
                // NB: si terminate_handler pas défini avec set_terminate( ): 
                // terminate called after throwing an instance of 'char*'
                // Aborted (core dumped)
                // code de retour:34304

                
  try{
    if (n == 11)
      k();      // k Une exception de type char*
                // Destructeur x = 11.5
                // e Destructeur x = -8.3
                // d 
                // code de retour: 0
                
    if (n == 12)
      l();      // l Une exception de type const char*
                // Destructeur x = 12.5
                // e Destructeur x = -8.3
                // d 
                // code de retour: 0
               
    if (n == 13)
      m();      // m Une exception de type string
                // Destructeur x = 13.5
                // e Destructeur x = -8.3
                // d 
                // code de retour: 0
               
    if (n == 14)
      try { p(); }              // On peut imbriquer des blocs try-catch
      catch (exception& e) {    // Classe mère de runtime_error
         cout << e.what() << endl; 
         throw 1; 
      }         // runtime error dans p
                // Autre exception 
                // h e Destructeur x = -8.3
                // d
                // code de retour:768

    if (n == 15)
      try { p(); }         
      catch (range_error& e) {  // Classe fille de runtime_error
         cout << e.what() << endl; 
         throw 4; 
      }         // Autre exception 
                // h e Destructeur x = -8.3
                // d
                // code de retour:768
               
    if (n == 16)
      throw 6 ; // Autre exception
                // h e Destructeur x = -8.3
                // d 
                // code de retour: 768
  }
  catch(char*)               { cout << "Une exception de type char*" << endl;}
  catch(const char* message) { cout << message << endl;}
  catch(string& message)     { cout << message << endl;}
  catch(...)                 { cout << "Autre exception " << endl;     throw;}
  
  // Fin normale: appeler terminate() s'il y a des exceptions non traitées;
  // Détruire les objets locaux, appeler exit(0), donc les fonctions empilées
  // par atexit(), ce qui provoque la fermeture des fichiers et connexions,
  // libère la mémoire, détruit les objets globaux (static) et vide les 
  // tampons, ce qui entraîne l'affichage de:
  
  // Destructeur x = n.5
  // e Destructeur x = -8.3
  // d    
  
  // Finalement: envoyer le code de retour 0
  // Ces actions sont faites par return 0; ajouté par le compilateur si non
  // présent à la fin de main()
}
