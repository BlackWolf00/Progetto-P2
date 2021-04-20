#include "rivista.h"

Rivista::Rivista(string t, string g, double p, int u, string e)
    : Item(t, g, p), numeroUscita(u), editore(e) {}

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

string Rivista::print() const {
    return Item::print() + "\n" + "Numero Uscita: " + std::to_string(numeroUscita) + " Editore " + editore + "\n";
}
