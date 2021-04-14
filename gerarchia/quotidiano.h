#ifndef QUOTIDIANO_H
#define QUOTIDIANO_H

#include "item.h"

class Quotidiano : public Item
{
private:
    int numeroUscita;
    string nomeGiornale;
public:
    Quotidiano(double p, int u, string g) : Item(p), numeroUscita(u), nomeGiornale(g) {}
    //TODO
    string getNomeGiornale() const;
};

#endif // QUOTIDIANO_H
