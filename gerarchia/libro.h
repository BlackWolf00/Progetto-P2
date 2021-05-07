#ifndef LIBRO_H
#define LIBRO_H

#include "item.h"

class Libro : public Item
{
private:
    string autore;
    int annoEdizione;
    string editore;
public:
    Libro(string t, string g, double p, double pn, string a,  int e, string c);
    Libro(const Libro&);
    Libro* clone() const;

    bool operator ==(const Item&) const;
    bool operator !=(const Item&) const;

    virtual string getEditore() const;

    string getAutore() const;
    int getAnnoEdizione() const;
    string print() const;

    QString getType() const;
    static Libro *unserialize(QXmlStreamReader&);
    void serializzaDati(QXmlStreamWriter&) const;
};

#endif // LIBRO_H
