#include "rivista.h"

Rivista::Rivista(string t, string g, double p, int u, string e)
    : Item(t, g, p), numeroUscita(u), editore(e) {}

int Rivista::getNumeroUscita() const {
    return numeroUscita;
}

string Rivista::getEditore() const {
    return editore;
}
