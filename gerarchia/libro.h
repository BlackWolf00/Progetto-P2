#ifndef LIBRO_H
#define LIBRO_H

#include "item.h"

using std::string;

class Libro : public Item
{
private:
    string autore;
    string annoEdizione;
    string editore;
public:
    Libro(string t, string g, double p, string a,  string e, string c);
    string getAnnoEdizione() const;

    virtual string getAutore() const;
};

#endif // LIBRO_H
