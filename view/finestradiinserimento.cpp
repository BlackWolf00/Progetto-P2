#include "finestradiinserimento.h"

FinestraDiInserimento::FinestraDiInserimento(QWidget *parent) :
    QDialog(parent), titolo(new QLineEdit("--Vuoto--", this)),
    genere(new QLineEdit("--Vuoto--", this)), prezzo(new QLineEdit("0.0", this)),
    autore(new QLineEdit("--Vuoto--", this)), editore(new QLineEdit("--Vuoto--", this)),
    annoEdizione(new QLineEdit("--Vuoto--", this)), numeroUscita(new QLineEdit("--Vuoto--", this)),
    libro(new QRadioButton("Libro", this)), fumetto(new QRadioButton("Fumetto", this)),
    mensile(new QRadioButton("Mensile", this)), settimanale(new QRadioButton("Mensile", this)),
    ok(new QPushButton("Conferma")), no(new QPushButton("Annulla")),
    dettagliBase(new QGroupBox("Dettagli base del prodotto", this)),
    boxElementoSelezionato(new QGroupBox("Seleziona un prodotto", this)),
    boxTipoSelezionato(new QGroupBox("Tipo di rivista", this)),
    dettagliLibro(new QGroupBox("Dettagli Libro")),
    dettagliFumetto(new QGroupBox("Dettagli Fumetto", this)),
    dettagliMensile(new QGroupBox("Dettagli Mensile", this)),
    dettagliSettimanale(new QGroupBox("Dettagli Settimanale", this)) {

    QVBoxLayout *layoutInserimentoPrincipale = new QVBoxLayout();
    QGridLayout *griglia = new QGridLayout();

    QLabel *labelTitolo = new QLabel("Titolo: ");
    QLabel *labelGenere = new QLabel("Genere: ");
    QLabel *labelPrezzo = new QLabel("Prezzo(€): ");
    QLabel *labelAutore = new QLabel("Autore: ");
    QLabel *labelEditore = new QLabel("Editore: ");
    QLabel *labelAnnoEdizione = new QLabel("Anno Edizione: ");
    QLabel *labelNumeroUscita = new QLabel("Numero Uscita: ");

    QHBoxLayout *layoutTitolo = new QHBoxLayout();
    QHBoxLayout *layoutGenere = new QHBoxLayout();
    QHBoxLayout *layoutPrezzo = new QHBoxLayout();
    QHBoxLayout *layoutAutore = new QHBoxLayout();
    QHBoxLayout *layoutEditore = new QHBoxLayout();
    QHBoxLayout *layoutAnnoEdizione = new QHBoxLayout();
    QHBoxLayout *layoutNumeroUscita = new QHBoxLayout();

    QVBoxLayout *layoutItemBase = new QVBoxLayout();
    QVBoxLayout *layoutLibro = new QVBoxLayout();
    QVBoxLayout *layoutFumetto = new QVBoxLayout();
    QVBoxLayout *layoutMensile = new QVBoxLayout();
    QVBoxLayout *layoutSettimanale = new QVBoxLayout();
    //QVBoxLayout *layoutTipo = new QVBoxLayout();
    QVBoxLayout *layoutElemento = new QVBoxLayout();

    layoutTitolo->addWidget(labelTitolo);
    layoutTitolo->addWidget(titolo);

    layoutGenere->addWidget(labelGenere);
    layoutGenere->addWidget(genere);

    layoutPrezzo->addWidget(labelPrezzo);
    layoutPrezzo->addWidget(prezzo);

    layoutAutore->addWidget(labelAutore);
    layoutAutore->addWidget(autore);

    layoutEditore->addWidget(labelEditore);
    layoutEditore->addWidget(editore);

    layoutAnnoEdizione->addWidget(labelAnnoEdizione);
    layoutAnnoEdizione->addWidget(annoEdizione);

    layoutNumeroUscita->addWidget(labelNumeroUscita);
    layoutNumeroUscita->addWidget(numeroUscita);

    layoutItemBase->addLayout(layoutTitolo);
    layoutItemBase->addLayout(layoutGenere);
    layoutItemBase->addLayout(layoutPrezzo);

    layoutLibro->addLayout(layoutAutore);
    layoutLibro->addLayout(layoutAnnoEdizione);
    layoutLibro->addLayout(layoutEditore);

    layoutFumetto->addLayout(layoutAutore);
    layoutFumetto->addLayout(layoutNumeroUscita);
    layoutFumetto->addLayout(layoutEditore);

    layoutRivista->addLayout(layoutNumeroUscita);
    layoutRivista->addLayout(layoutEditore);

    //layoutMensile->addLayout(layoutNumeroUscita);
    //layoutMensile->addLayout(layoutEditore);

    layoutElemento->addWidget(libro);
    layoutElemento->addWidget(fumetto);
    layoutElemento->addWidget(mensile);
    layoutElemento->addWidget(settimanale);

    dettagliBase->setLayout(layoutItemBase);
    boxElementoSelezionato->setLayout(layoutElemento);
    dettagliLibro->setLayout(layoutLibro);
    dettagliFumetto->setLayout(layoutFumetto);
    dettagliSettimanale->setLayout(layoutSettimanale);
    dettagliMensile->setLayout(layoutMensile);

    dettagliLibro->setVisible(false);
    dettagliFumetto->setVisible(false);
    dettagliSettimanale->setVisible(false);
    dettagliMensile->setVisible(false);

    griglia->addWidget(dettagliBase, 0,0);
    griglia->addWidget(boxElementoSelezionato, 0,1);
    griglia->addWidget(dettagliLibro, 1,0);
    griglia->addWidget(dettagliFumetto, 1,0);
    griglia->addWidget(dettagliSettimanale, 1,0);
    griglia->addWidget(dettagliMensile, 1,0);
    griglia->addWidget(no, 2,0);
    griglia->addWidget(ok, 2,1);

    dettagliBase->setFixedWidth(300);
    boxElementoSelezionato->setFixedWidth(300);
    dettagliLibro->setFixedWidth(300);
    dettagliFumetto->setFixedWidth(300);
    dettagliSettimanale->setFixedWidth(300);
    dettagliMensile->setFixedWidth(300);

    layoutInserimentoPrincipale->addLayout(griglia);
    setLayout(layoutInserimentoPrincipale);
    setWindowTitle("Inserimento dati");

    connect(libro, SIGNAL(clicked()), this, SLOT(showLibro()));
    connect(fumetto, SIGNAL(clicked()), this, SLOT(showFumetto()));
    connect(settimanale, SIGNAL(clicked()), this, SLOT(showSettimanale()));
    connect(mensile, SIGNAL(clicked()), this, SLOT(showMensile()));
    connect(ok, SIGNAL(clicked()), this, SLOT(conferma()));
    connect(no, SIGNAL(clicked()), this, SLOT(annulla()));

}


