#ifndef MENSILE_H
#define MENSILE_H

#include "rivista.h"

using std::string;

class Mensile : public Rivista
{
private:

public:
    Mensile(string t, string g, double p, double pn, int u, string e);
    Mensile(const Mensile&);
    virtual Mensile* clone() const;

    bool operator==(const Item&) const;
    bool operator!=(const Item&) const;

    QString getType() const;
    string print() const;
    static Mensile *unserialize(QXmlStreamReader&);
    void serializzaDati(QXmlStreamWriter&) const;
};

#endif // MENSILE_H
