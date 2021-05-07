#ifndef RIVISTA_H
#define RIVISTA_H

#include "item.h"

using std::string;

class Rivista : public Item
{
private:
    int numeroUscita;
    string editore;
    bool settimanale;
    bool mensile;
public:
    Rivista(string t, string g, double p, double pn, int u, string e, bool s, bool m);
    Rivista(const Rivista&);
    Rivista* clone() const = 0;

    bool operator==(const Item&) const;
    bool operator!=(const Item&) const;


    string getEditore() const;
    int getNumeroUscita() const;

    bool getSettimanale() const;
    bool getMensile() const;

    QString getType() const = 0;
    string print() const;
    virtual void serializzaDati(QXmlStreamWriter&) const = 0;

};

#endif // RIVISTA_H
