#ifndef LIBRO_H
#define LIBRO_H

#include "item.h"

using std::string;

class Libro : public Item
{
private:
    string titolo;
    string autore;
    string genere;
    string annoEdizione;
    string casaEditrice;
public:
    Libro(double p, string t, string a, string g, string e, string c);
    //DISTRUTTORE FORSE
    string getAutore() const;
    string getAnnoEdizione() const;
    string getCasaEditrice() const;
};

#endif // LIBRO_H
