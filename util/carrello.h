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
};

#endif // CARRELLO_H
