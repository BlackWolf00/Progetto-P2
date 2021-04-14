#ifndef QUOTIDIANO_H
#define QUOTIDIANO_H

#include "item.h"

class Quotidiano : public Item
{
private:
    int numeroUscita;
    string nomeGiornale;
public:
    Quotidiano(double p, int u, string g);
    //TODO
    string getNomeGiornale() const;
};

#endif // QUOTIDIANO_H
