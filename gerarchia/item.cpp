#include "item.h"

Item::Item(string t, string g, double p, double pn)
    : titolo(t), genere(g), prezzo(p), prezzoNoleggio(pn) {}

Item::Item(const Item& i)
    : titolo(i.titolo), genere(i.genere), prezzo(i.prezzo), prezzoNoleggio(i.prezzoNoleggio) {}

bool Item::operator==(const Item& i) const {
    return match(titolo, i.getTitolo()) && match(genere, i.getGenere());
}

bool Item::operator!=(const Item& i) const {
    return titolo != i.getTitolo() || genere != i.getTitolo();
}

bool Item::operator<(const Item& i) const {
    if(titolo < i.getTitolo())
        return true;
    else {
        if(titolo == i.getTitolo())
            if(genere < i.getGenere())
                return true;
    }

    return false;
}

bool Item::operator>(const Item& i) const {
    if(titolo > i.getTitolo())
        return true;
    else {
        if(titolo == i.getTitolo())
            if(genere > i.getGenere())
                return true;
    }

    return false;
}

string Item::getTitolo() const {
    return titolo;
}

string Item::getGenere() const {
    return genere;
}

double Item::getPrezzo() const {
    return prezzo;
}

double Item::getPrezzoNoleggio() const {
    return prezzoNoleggio;
}

string Item::print() const {
    return "Titolo: " + titolo + "\n" + "Genere: " + genere + "\n" + "Prezzo: " + QString::number(prezzo, 'g', 2).toStdString() + "€" + "\n" +
            "Costo Giornaliero: " + QString::number(prezzoNoleggio, 'g', 2).toStdString() + "€" + "\n";
}
