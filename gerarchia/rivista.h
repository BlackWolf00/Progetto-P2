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
    Rivista* clone() const = 0;

    bool operator==(const Item&) const;
    bool operator!=(const Item&) const;

    virtual int getNumeroUscita() const;
    virtual string getEditore() const;

    virtual string getAutore() const;

    QString getType() const = 0;
    string print() const;
    virtual void serializzaDati(QXmlStreamWriter&) const = 0;

};

#endif // RIVISTA_H
