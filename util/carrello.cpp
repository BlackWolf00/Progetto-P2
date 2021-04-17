#include "carrello.h"

Carrello::Carrello() : carrello() {}

Carrello::Carrello(const Carrello& c) : carrello(c.carrello) {}

Carrello::~Carrello() {}

void Carrello::inserisciNelCarrello(DeepPtr<Item> i, unsigned int u) {
    if(carrello.contains(i))
        carrello[i] += u;
    else
        carrello.insert(i, u);
}

bool Carrello::eliminaDaCarrello(DeepPtr<Item> i) {
    auto it = carrello.find(i);
    if(carrello.end() != it) {
        carrello.erase(it);
        return true;
    }
    return false;
}

void Carrello::eliminaDaCarrelloAIndice(unsigned int i){
    auto it = carrello.begin();
    if(i<(uint)carrello.size()) {
         for(unsigned int k = 0; k<i; k++)
            it++;
        carrello.erase(it);
    }
}
