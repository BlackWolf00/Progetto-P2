#ifndef FUMETTO_H
#define FUMETTO_H

#include "item.h"

class Fumetto : public Item
{
private:
    int numeroUscita;
    string autore;
    string editore;
public:
    Fumetto(string t, string g, double p, int n, string a, string e);

    virtual int getNumeroUscita() const;
    virtual string getAutore() const;
    virtual string getEditore() const;
};

#endif // FUMETTO_H
