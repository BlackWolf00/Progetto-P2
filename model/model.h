#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QDate>
#include <QMap>

#include "template/container.h"
#include "template/deepptr.h"
#include "gerarchia/item.h"
#include "gerarchia/fumetto.h"
#include "gerarchia/rivista.h"
#include "gerarchia/mensile.h"
#include "gerarchia/settimanale.h"
#include "util/carrello.h"

class Model : public QObject
{
    Q_OBJECT
private:
    QDate data;
    Container<DeepPtr<Item>> catalogo;
    Carrello noleggio, acquisto;

    QString filename;

public:
    explicit Model(QObject *parent = nullptr);

    void rimuoviDaCatalogo(const unsigned int);
    //void rimuoviNoleggio(const unsigned int);
    void rimuoviAcquisto(const unsigned int);

    //void aggiungiNolleggio();
    void aggiungiAcquisto(const unsigned int, const unsigned int);

    bool modificaOggetto(const unsigned int, const QStringList);

    //QString getDettagliCatalogo(const unsigned int) const;
    //QString getDettagliNoleggio(const unsigned int) const;
    //QString getDettagliAcquisto(const unsigned int) const;

    QStringList getElementiCatalogo(const unsigned int) const;
    //QStringList getElementeiNoleggio(const unsigned int) const;
    QStringList getElementiAcquisto(const unsigned int) const;

    //unsigned int getQuantitaNoleggio(const unsigned int) const;
    unsigned int getQuantitaAcquisto(const unsigned int) const;

    //void setQuantitaNoleggio(const unsigned int, const unsigned int);
    void setQuantitaAcquisto(const unsigned int, const unsigned int);

    QStringList getCatalogo() const;
    QStringList getCatalogoFiltrato(const QString, QMap<unsigned int, unsigned int> &) const;
    //QStringList getNoleggio() const;
    QStringList getAcquisto() const;

    //double getPrezziNoleggio() const;
    double getPrezziAcquisto() const;

    bool controllaNelCatalogo(const QStringList) const;

    unsigned int trovaElementoNelCatalogo(const QStringList) const;

    bool trovatoQualcosa() const;
    void pulisciSpazio();

    void setData(QDate);
    QDate getData() const;

public slots:

    void aggiungiNelCatalogo(const QStringList);

    void setFilename(const QString flname);
    QString caricaDati();
    //QString serializzaDati();

signals:

    void mostraCatalogo(const QStringList);
    //void quantitaCambiataNoleggio();
    void quantitaCambiataAcquisto();
    void elementiRimossiDaCatalogo();
    //void elementiRimossiDaNoleggio();
    void elementiRimossiDaAcquisto();
    void nomeCambiato();
    void quantitaCambiata();
    void elementoAggiunto();
    //void noleggioAggiuto();
    void acquistoAggiunto();
    void catalogoRimosso();
    //void noleggioRimosso();
    void acquistoRimosso();
};

#endif // MODEL_H
