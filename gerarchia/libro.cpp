#include "libro.h"

Libro::Libro(string t, string g, double p, string a, string e, string c)
    : Item(t, g, p), autore(a), annoEdizione(e), editore(c) {}

string Libro::getAutore() const {
    return autore;
}

string Libro::getAnnoEdizione() const {
    return annoEdizione;
}
