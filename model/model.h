#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QDate>
#include <QMap>

#include "template/container.h"
#include "template/deepptr.h"
#include "gerarchia/item.h"
#include "util/carrello.h"

class Model : public QObject
{
    Q_OBJECT
private:
    QDate data;
    Container<DeepPtr<Item>> catalogo;
    Carrello noleggio, acquisto;

    //QString filename;

public:
    explicit Model(QObject *parent = nullptr);

    void aggiungiAcquisto(const unsigned int, const unsigned int);

    void rimuoviAcquisto(const unsigned int);
};

#endif // MODEL_H
