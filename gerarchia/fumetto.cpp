#include "fumetto.h"

Fumetto::Fumetto(string t, string g, double p, int n, string a, string e)
    : Item(t, g, p), numeroUscita(n), autore(a), editore(e) {}

int Fumetto::getNumeroUscita() const {
    return numeroUscita;
}

string Fumetto::getAutore() const {
    return autore;
}

string Fumetto::getEditore() const {
    return editore;
}
