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
    QLineEdit *titolo, *genere, *prezzo, *autore, *editore, *annoEdizione, *numeroUscita;
    QRadioButton *libro, *fumetto, *mensile, *settimanale;

    QPushButton *ok, *no;

    QGroupBox *dettagliBase;
    QGroupBox *boxElementoSelezionato;
    QGroupBox *boxTipoSelezionato;
    QGroupBox *dettagliLibro;
    QGroupBox *dettagliFumetto;
    //QGroupBox *dettagliRivista;
    QGroupBox *dettagliMensile;
    QGroupBox *dettagliSettimanale;

public:
    explicit FinestraDiInserimento(QWidget *parent = nullptr);

    void resetPerNuovoInserimento();
    void displayErroreInput();

public slots:

    void showLibro();
    void showFumetto();
    void showSettimanale();
    void showMensile();

    virtual void conferma();
    void annulla();

signals:

    void attivaLibro();
    void attivaFumetto();
    void attivaSettimanale();
    void attivaMensile();

    void mandaDettagliOggetto(const QStringList);
    void erroreInput();
};

#endif // FINESTRADIINSERIMENTO_H
