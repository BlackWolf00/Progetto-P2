#ifndef ITEM_H
#define ITEM_H

#include <string>

using std::string;

class Item
{
private:
    string titolo;
    string genere;
    const double prezzo;
public:
    Item(string t, string g, double p);

    string getTitolo() const;
    string getGenere() const;
    double getPrezzo() const;

    virtual ~Item() = default;
    virtual string getAutore() const = 0;
    virtual int getNumeroUscita() const = 0;
    virtual string getEditore() const = 0;
};

#endif // ITEM_H
