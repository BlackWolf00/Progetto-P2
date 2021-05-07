#ifndef FINESTRADIINSERIMENTO_H
#define FINESTRADIINSERIMENTO_H

#include <QDialog>
#include <QRadioButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QMessageBox>

class FinestraDiInserimento : public QDialog
{
    Q_OBJECT
protected:
    QLineEdit *titolo, *genere, *prezzo, *prezzoNoleggio, *autoreL, *autoreF,
    *numeroUscitaF, *numeroUscitaR, *editoreL, *editoreF, *editoreR, *annoEdizione;
    QRadioButton *libro, *fumetto, *rivista;
    QCheckBox  *mensile, *settimanale;

    QPushButton *ok, *no;

    QGroupBox *dettagliBase;
    QGroupBox *boxElementoSelezionato;
    QGroupBox *dettagliLibro;
    QGroupBox *dettagliFumetto;
    QGroupBox *dettagliRivista;
    QGroupBox *boxTipoSelezionato;

public:
    explicit FinestraDiInserimento(QWidget *parent = nullptr);

    void resetPerNuovoInserimento();
    void displayErroreInput();

public slots:

    void showLibro();
    void showFumetto();
    void showRivista();

    virtual void conferma();
    void annulla();

signals:

    void attivaLibro();
    void attivaFumetto();
    void attivaRivista();

    void mandaDettagliOggetto(const QStringList);
    void erroreInput();
};

#endif // FINESTRADIINSERIMENTO_H
