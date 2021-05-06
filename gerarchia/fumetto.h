#ifndef FUMETTO_H
#define FUMETTO_H

#include "item.h"

class Fumetto : public Item
{
private:
    string autore;
    int numeroUscita;
    string editore;
public:
    Fumetto(string t, string g, double p, double pn, string a, int n, string e);
    Fumetto(const Fumetto&);
    Fumetto* clone() const;

    bool operator ==(const Item&) const;
    bool operator !=(const Item&) const;


    virtual string getEditore() const;

    string getAutore() const;
    int getNumeroUscita() const;
    string print() const;

    QString getType() const;
    static Fumetto *unserialize(QXmlStreamReader&);
    void serializzaDati(QXmlStreamWriter&) const;

};

#endif // FUMETTO_H
