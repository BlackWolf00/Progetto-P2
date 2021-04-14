#include "item.h"

Item::Item(double p) : prezzo(p) {}

double Item::getPrezzo() const {
    return prezzo;
}
