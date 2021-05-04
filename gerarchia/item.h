#ifndef ITEM_H
#define ITEM_H

#include <QXmlStreamReader>
#include <QXmlStreamWriter>

using std::string;

class Item
{
private:
    string titolo;
    string genere;
    const double prezzo;
    const double prezzoNoleggio;
public:
    Item(string t, string g, double p, double pn);
    Item(const Item&);
    virtual Item*clone() const = 0;
    virtual ~Item() = default;

    string getTitolo() const;
    string getGenere() const;
    double getPrezzo() const;
    double getPrezzoNoleggio() const;

    virtual bool operator==(const Item&) const;
    virtual bool operator!=(const Item&) const;
    virtual bool operator>(const Item&) const;
    virtual bool operator<(const Item&) const;

    static bool match(string, string);

    virtual string getAutore() const = 0;
    virtual int getNumeroUscita() const = 0;
    virtual string getEditore() const = 0;

    virtual QString getType() const = 0;
    virtual string print() const;
    virtual void serializzaDati(QXmlStreamWriter&) const = 0;
};

#endif // ITEM_H
