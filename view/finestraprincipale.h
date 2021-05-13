#ifndef FINESTRAPRINCIPALE_H
#define FINESTRAPRINCIPALE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
#include <QDateEdit>
#include <QMenuBar>
#include <QSpinBox>
#include <QPushButton>
#include <QBoxLayout>
#include <QString>

#include "util/listasmart.h"

class FinestraPrincipale : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *dettagli, *totnoleggio, *totacquisto;
    ListaSmart *elemento, *noleggio, *acquisto;
    QDateEdit *data;
    QSpinBox *quantita;
    QLineEdit *nome, *cf, *trova;

public:
    explicit FinestraPrincipale(QWidget *parent = nullptr);

    void displayCatalogo(const QStringList);
    void displayNoleggio(const QStringList);
    void displayAcquisto(const QStringList);
    void displayErroreInput();
    void displayNessunaSelezione();
    void displayDettagli(const QString);
    void displayTotale(const double, const double);
    void displayErroreApertura();
    void displayErroreCF();
    void displayElementoEsistente();
    void displayCarica(QString);
    void displaySalva(QString);

    bool isSelezionato() const;
    unsigned int getCatalogoSelezionato() const;

    const QString getParolaChiave() const;

    QString getNomeCliente() const;
    QString getCFCliente() const;

public slots:

    void aggiornaDettagli(QString info);
    void generaNoleggio();
    void generaAcquisto();
    void distruggiNoleggio();
    void distruggiAcquisto();

    void catalogoSelezionato(const int);
    void noleggioSelezionato(const int);
    void acquistoSelezionato(const int);

    void rimuoviSelezionato();

signals:

    void apriFinestraAggiungiACatalogo();
    void richiestaModifica();
    void richiestaRimuoviDaCatalogo(const unsigned int);
    void apriFinestraCaricamento();
    void apriFinestraSalvataggio();
    void apriFinestraSalvaPDF();
    void aggiornaRicerca();
    void clickNoleggio(const unsigned int i, const unsigned int u);
    void clickAcquisto(const unsigned int i, const unsigned int u);
    void clickRimuoviNoleggio(const unsigned int i);
    void clickRimuoviAcquisto(const unsigned int i);
    void richiestaDettagliCatalogo(const unsigned int);
    void richiestaDettagliNoleggio(const unsigned int);
    void richiestaDettagliAcquisto(const unsigned int);
};

#endif // FINESTRAPRINCIPALE_H
