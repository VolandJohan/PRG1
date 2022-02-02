#include <string>
#include <sstream>

class Mot {
    std::string mot;
    size_t nb_occurrences;
 public :
    Mot(std::string mot, size_t nb_occurrences) {
        mot = mot;
        nb_occurrences = nb_occurrences;
    }
    Mot(std::string mot) {
        mot = mot;
        nb_occurrences = 0;
    }
    Mot &operator++ () { nb_occurrences += 1; return *this;}
    Mot operator++(int) {
        Mot temp = *this;
        ++temp.nb_occurrences;
        return temp; 
    }
    friend std::ostream& operator<<(std::ostream& os, const Mot& val) {
        os << val.mot << " " << val.nb_occurrences;
        return os;
    }
};