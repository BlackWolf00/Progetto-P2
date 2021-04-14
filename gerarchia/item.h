#ifndef ITEM_H
#define ITEM_H

using std::string;

class Item
{
private:
    double prezzo;
public:
    Item(double p=2) : prezzo(p) {}
    virtual ~Item();
    virtual string getTitolo() const = 0;
    virtual double getPrezzo() const = 0;
    virtual string getGenere() const = 0;
    virtual string getNumeroUscita() const = 0;

#endif // ITEM_H
