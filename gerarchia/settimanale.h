#ifndef SETTIMANALE_H
#define SETTIMANALE_H

#include "rivista.h"

using std::string;

class Settimanale : public Rivista
{
private:

public:
    Settimanale(string t, string g, double p, int u, string e);
    Settimanale(const Settimanale&);
    virtual Settimanale* clone() const;

    bool operator==(const Item&) const;
    bool operator!=(const Item&) const;

    QString getType() const;
    string print() const;
    static Settimanale *unserialize(QXmlStreamReader&);
    void serializzaDati(QXmlStreamWriter&) const;
};

#endif // SETTIMANALE_H
