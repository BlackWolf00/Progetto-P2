#include "rivista.h"

Rivista::Rivista(string t, string g, double p, double pn, int u, string e)
    : Item(t, g, p, pn), numeroUscita(u), editore(e) {}

Rivista::Rivista(const Rivista& r) : Item(r), numeroUscita(r.getNumeroUscita()), editore(r.getEditore()) {}

bool Rivista::operator==(const Item& i) const {
    return dynamic_cast<const Rivista*>(&i) && Item::operator==(i) && numeroUscita==(static_cast<const Rivista*>(&i))->getNumeroUscita() &&
            editore==(static_cast<const Rivista*>(&i))->getEditore();
}

bool Rivista::operator!=(const Item& i) const {
    return dynamic_cast<const Rivista*>(&i) && Item::operator!=(i) && numeroUscita!=(static_cast<const Rivista*>(&i))->getNumeroUscita() &&
            editore!=(static_cast<const Rivista*>(&i))->getEditore();
}

int Rivista::getNumeroUscita() const {
    return numeroUscita;
}

string Rivista::getEditore() const {
    return editore;
}

string Rivista::getAutore() const { //eliminare
    return 0;
}

string Rivista::print() const {
    return Item::print() + "\n" + "Tipologia: Rivista" + "\n" + "Numero Uscita: " + std::to_string(numeroUscita) + "\n" + "Editore " + editore + "\n";
}
