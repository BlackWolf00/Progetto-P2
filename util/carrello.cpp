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

QMap<DeepPtr<Item>, unsigned int>::const_iterator Carrello::cercaNelCarrello(DeepPtr<Item> i) const {
    return carrello.find(i);
}

DeepPtr<Item> Carrello::cercaAIndice(unsigned int i) const {
    auto it = carrello.begin();
    for(unsigned int k = 0; k < i; k++)
        it++;
    return it.key();
}

unsigned int Carrello::rimuoviQuantita(DeepPtr<Item> i, unsigned int q) {
    auto it = carrello.find(i);
    if(carrello.end() != it) {
        if (it.value() > q) {
            it.value()-=q;
            return it.value();
        }
    }
    return 0;
}

unsigned int Carrello::getQuantita(DeepPtr<Item> i) const {
    auto it = cercaNelCarrello(i);
    if(*it)
        return it.value();
    return 0;
}

double Carrello::getTotalePrezzoAcquisto() const {
    double totale = 0;
    double costo_tmp = 0;
    for(auto it = carrello.begin(); it != carrello.end(); it++) {
        costo_tmp = (*(it.key())).getPrezzo();
        totale += it.value() * costo_tmp;
    }
    return totale;
}

double Carrello::getTotalePrezzoNoleggio() const {
    double totale = 0;
    double costo_tmp = 0;
    for(auto it = carrello.begin(); it != carrello.end(); it++) {
        costo_tmp = (*(it.key())).getPrezzoNoleggio();
        totale += it.value() * costo_tmp;
    }
    return totale;
}

void Carrello::setQuantita(DeepPtr<Item> i, unsigned int q) {
    auto it = carrello.find(i);
    it.value() = q;
}

bool Carrello::is_vuoto() const {
    return carrello.empty();
}

void Carrello::pulisci() {
    carrello.clear();
}

QStringList Carrello::stampaCarrello() const {
    QStringList stampa;
    QString label;

    auto it = carrello.begin();
    while(it != carrello.end()) {
        label = (QString::fromStdString(((it.key())->getTitolo()) + "(" + ((it.key())->getGenere()) + ")"));
        label += QString::fromStdString("        Copie: ");
        label += QString::number(it.value());
        stampa.push_back(label);
        ++it;
    }
    return stampa;
}
