#ifndef RIVISTA_H
#define RIVISTA_H

#include "item.h"

using std::string;

class Rivista : public Item
{
private:
    int numeroUscita;
    string editore;
public:
    Rivista(string t, string g, double p, int u, string e);

    virtual int getNumeroUscita() const;
    virtual string getEditore() const;
};

#endif // RIVISTA_H
