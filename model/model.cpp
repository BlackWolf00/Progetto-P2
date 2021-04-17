#include "model.h"

Model::Model(QObject *parent)
    : QObject(parent), data(QDate::currentDate()), catalogo(), noleggio(), acquisto() {}

void Model::aggiungiAcquisto(const unsigned int i, const unsigned int u) {
    DeepPtr<Item> inserisci(catalogo.searchAtIndex(i));
    acquisto.inserisciNelCarrello(inserisci, u);
    emit acquistoEffetuato();
}

void Model::rimuoviAcquisto(const unsigned int i) {
    acquisto.eliminaDaCarrelloAIndice(i);
    emit acquistoEliminato;
}
