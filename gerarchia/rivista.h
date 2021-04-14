#ifndef RIVISTA_H
#define RIVISTA_H

#include "item.h"

using std::string;

class Rivista : public Item
{
private:
    int numeroUscita;
    string titolo;
    string genere;
    string editore;
public:
    Rivista(double p, int u, string t, string g, string e);
    //TODO
    string getEditore() const;
};

#endif // RIVISTA_H
