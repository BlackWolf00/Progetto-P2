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
    Fumetto(const Fumetto&);
    Fumetto* clone() const;

    virtual int getNumeroUscita() const;
    virtual string getAutore() const;
    virtual string getEditore() const;

    string print() const;

    QString getType() const;
    static Fumetto *unserialize(QXmlStreamReader&);
    void serializzaDati(QXmlStreamWriter&) const;

};

#endif // FUMETTO_H
