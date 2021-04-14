#ifndef ITEM_H
#define ITEM_H

#include <string>

using std::string;

class Item
{
private:
    const double prezzo;
public:
    Item(double p);
    virtual ~Item() = default;
    virtual string getTitolo() const = 0;
    virtual double getPrezzo() const = 0;
    virtual string getGenere() const = 0;
    virtual string getNumeroUscita() const = 0;
};

#endif // ITEM_H
