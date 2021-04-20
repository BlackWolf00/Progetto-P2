#ifndef CARRELLO_H
#define CARRELLO_H

#include "gerarchia/item.h"
#include "gerarchia/libro.h"
#include "gerarchia/rivista.h"
#include "gerarchia/fumetto.h"
#include "template/deepptr.h"
#include <QMap>

using std::map;

class Carrello
{
private:
    QMap<DeepPtr<Item>, unsigned int> carrello;
public:
    Carrello();
    Carrello(const Carrello&);
    ~Carrello();

    void inserisciNelCarrello(DeepPtr<Item>, unsigned int);
    bool eliminaDaCarrello(DeepPtr<Item>);
    void eliminaDaCarrelloAIndice(unsigned int i);
    QMap<DeepPtr<Item>, unsigned int>::const_iterator cercaNelCarrello(DeepPtr<Item>) const;
    DeepPtr<Item> cercaAIndice(unsigned int) const;
    unsigned int rimuoviQuantita(DeepPtr<Item>, unsigned int);
    unsigned int getQuantita(DeepPtr<Item>) const;
    double getTotalePrezzoAcquisto() const;
    //double getTotalePrezzoNoleggio() const;
    void setQuantita(DeepPtr<Item>, unsigned int);
    bool is_vuoto() const;
    void pulisci();

    //QStringList stampaCarrello() const;
};

#endif // CARRELLO_H
