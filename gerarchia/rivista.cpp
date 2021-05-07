#include "rivista.h"

Rivista::Rivista(string t, string g, double p, double pn, int u, string e, bool s, bool m)
    : Item(t, g, p, pn), numeroUscita(u), editore(e), settimanale(s), mensile(m) {}

Rivista::Rivista(const Rivista& r) : Item(r), numeroUscita(r.getNumeroUscita()), editore(r.getEditore()),
                                        settimanale(r.getSettimanale()), mensile(r.getMensile()) {}

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

bool Rivista::getSettimanale() const {
    return settimanale;
}

bool Rivista::getMensile() const {
    return mensile;
}

string Rivista::print() const {
    if(settimanale)
        return Item::print() + "\n" + "Tipologia: Rivista Settimanale" + "\n" + "Numero Uscita: " + std::to_string(numeroUscita) + "\n" + "Editore " + editore + "\n";
    else
        return Item::print() + "\n" + "Tipologia: Rivista Mensile" + "\n" + "Numero Uscita: " + std::to_string(numeroUscita) + "\n" + "Editore " + editore + "\n";
}
