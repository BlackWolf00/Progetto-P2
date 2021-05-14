#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QStringList>
#include <QMap>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>

#include "model/model.h"
#include "view/finestraprincipale.h"
#include "view/finestradiinserimento.h"
#include "view/finestradimodifica.h"

class Controller : public QWidget
{
    Q_OBJECT
private:
    Model *modello;
    FinestraPrincipale *finestraP;
    FinestraDiInserimento *finestraI;
    FinestraDiModifica *finestraM;
    QMap<unsigned int, unsigned int> indexTranslate;
public:
    explicit Controller(QWidget *parent = nullptr);

public slots:

    void aggiungiACatalogo(const QStringList);
    void aggiungiANoleggio(const unsigned int, const unsigned int);
    void aggiungiAdAcquisto(const unsigned int, const unsigned int);

    void removeCatalogo(const unsigned int);
    void removeNoleggio(const unsigned int);
    void removeAcquisto(const unsigned int);

    void getDettagliCatalogo(const unsigned int) const;
    void getDettagliNoleggio(const unsigned int) const;
    void getDettagliAcquisto(const unsigned int) const;

    void sendPerScambio(const unsigned int, const QStringList);

    void refreshCatalogo();
    void refreshNoleggio();
    void refreshAcquisto();

    void apriAggiungi() const;
    void apriModifica() const;
    void apriSalva() const;
    void apriSalvaPDF() const;
    void apriCarica();

    void erroreInput();

};

#endif // CONTROLLER_H
