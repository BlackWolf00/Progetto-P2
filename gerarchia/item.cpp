#include "item.h"

Item::Item(string t, string g, double p)
    : titolo(t), genere(g), prezzo(p) {}

string Item::getTitolo() const {
    return titolo;
}

string Item::getGenere() const {
    return genere;
}

double Item::getPrezzo() const {
    return prezzo;
}
