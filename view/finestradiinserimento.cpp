#include "finestradiinserimento.h"

FinestraDiInserimento::FinestraDiInserimento(QWidget *parent) :
    QDialog(parent), titolo(new QLineEdit("--Vuoto--", this)),
    genere(new QLineEdit("--Vuoto--", this)), prezzo(new QLineEdit("0.0", this)),
    prezzoNoleggio(new QLineEdit("0.0", this)),
    autoreL(new QLineEdit("--Vuoto--", this)), autoreF(new QLineEdit("--Vuoto--", this)),
    numeroUscitaF(new QLineEdit("0", this)), numeroUscitaR(new QLineEdit("0", this)),
    editoreL(new QLineEdit("--Vuoto--", this)), editoreF(new QLineEdit("--Vuoto--", this)),
    editoreR(new QLineEdit("--Vuoto--", this)),
    annoEdizione(new QLineEdit("--Vuoto--", this)),
    libro(new QRadioButton("Libro", this)), fumetto(new QRadioButton("Fumetto", this)),
    rivista(new QRadioButton("Rivista", this)),
    mensile(new QCheckBox("Mensile", this)), settimanale(new QCheckBox("Settimanale", this)),
    ok(new QPushButton("Conferma")), no(new QPushButton("Annulla")),
    dettagliBase(new QGroupBox("Dettagli base del prodotto", this)),
    boxElementoSelezionato(new QGroupBox("Seleziona un prodotto", this)),
    dettagliLibro(new QGroupBox("Dettagli Libro")),
    dettagliFumetto(new QGroupBox("Dettagli Fumetto", this)),
    dettagliRivista(new QGroupBox("Dettagli Rivista", this)),
    boxTipoSelezionato(new QGroupBox("Tipo di rivista", this)) {

    QVBoxLayout *layoutInserimentoPrincipale = new QVBoxLayout();
    QGridLayout *griglia = new QGridLayout();

    //LABEL BASE

    QLabel *labelTitolo = new QLabel("Titolo: ");
    QLabel *labelGenere = new QLabel("Genere: ");
    QLabel *labelPrezzo = new QLabel("Prezzo(€): ");
    QLabel *labelPrezzoNoleggio = new QLabel("Costo Giornaliero(€): ");

    //LABEL LIBRO

    QLabel *labelAutoreL = new QLabel("Autore: ");
    QLabel *labelEditoreL = new QLabel("Editore: ");
    QLabel *labelAnnoEdizione = new QLabel("Anno Edizione: ");

    //LABEL FUMETTO

    QLabel *labelNumeroUscitaF = new QLabel("Numero Uscita: ");
    QLabel *labelAutoreF = new QLabel("Autore: ");
    QLabel *labelEditoreF = new QLabel("Editore: ");

    //LABEL RIVISTA

    QLabel *labelNumeroUscitaR = new QLabel("Numero Uscita: ");
    QLabel *labelEditoreR = new QLabel("Editore: ");

    //LAYOUT BASE

    QHBoxLayout *layoutTitolo = new QHBoxLayout();
    QHBoxLayout *layoutGenere = new QHBoxLayout();
    QHBoxLayout *layoutPrezzo = new QHBoxLayout();
    QHBoxLayout *layoutPrezzoNoleggio = new QHBoxLayout();

    //LAYOUT LIBRO

    QHBoxLayout *layoutAutoreL = new QHBoxLayout();
    QHBoxLayout *layoutEditoreL = new QHBoxLayout();
    QHBoxLayout *layoutAnnoEdizione = new QHBoxLayout();

    //LAYOUT FUMETTO

    QHBoxLayout *layoutNumeroUscitaF = new QHBoxLayout();
    QHBoxLayout *layoutAutoreF = new QHBoxLayout();
    QHBoxLayout *layoutEditoreF = new QHBoxLayout();

    //LAYOUT RIVISTA

    QHBoxLayout *layoutNumeroUscitaR = new QHBoxLayout();
    QHBoxLayout *layoutEditoreR = new QHBoxLayout();

    QVBoxLayout *layoutItemBase = new QVBoxLayout();
    QVBoxLayout *layoutLibro = new QVBoxLayout();
    QVBoxLayout *layoutFumetto = new QVBoxLayout();
    QVBoxLayout *layoutRivista = new QVBoxLayout();
    QVBoxLayout *layoutTipo = new QVBoxLayout();
    QVBoxLayout *layoutElemento = new QVBoxLayout();

    layoutTitolo->addWidget(labelTitolo);
    layoutTitolo->addWidget(titolo);

    layoutGenere->addWidget(labelGenere);
    layoutGenere->addWidget(genere);

    layoutPrezzo->addWidget(labelPrezzo);
    layoutPrezzo->addWidget(prezzo);

    layoutPrezzoNoleggio->addWidget(labelPrezzoNoleggio);
    layoutPrezzoNoleggio->addWidget(prezzoNoleggio);

    layoutAutoreL->addWidget(labelAutoreL);
    layoutAutoreL->addWidget(autoreL);

    layoutAutoreF->addWidget(labelAutoreF);
    layoutAutoreF->addWidget(autoreF);

    layoutEditoreL->addWidget(labelEditoreL);
    layoutEditoreL->addWidget(editoreL);

    layoutEditoreF->addWidget(labelEditoreF);
    layoutEditoreF->addWidget(editoreF);

    layoutEditoreR->addWidget(labelEditoreR);
    layoutEditoreR->addWidget(editoreR);

    layoutAnnoEdizione->addWidget(labelAnnoEdizione);
    layoutAnnoEdizione->addWidget(annoEdizione);

    layoutNumeroUscitaF->addWidget(labelNumeroUscitaF);
    layoutNumeroUscitaF->addWidget(numeroUscitaF);

    layoutNumeroUscitaR->addWidget(labelNumeroUscitaR);
    layoutNumeroUscitaR->addWidget(numeroUscitaR);

    //ATTACCO label piccoli a layouit selezione //DA RIMUOVERE

    layoutItemBase->addLayout(layoutTitolo);
    layoutItemBase->addLayout(layoutGenere);
    layoutItemBase->addLayout(layoutPrezzo);
    layoutItemBase->addLayout(layoutPrezzoNoleggio);

    layoutLibro->addLayout(layoutAutoreL);
    layoutLibro->addLayout(layoutAnnoEdizione);
    layoutLibro->addLayout(layoutEditoreL);

    layoutFumetto->addLayout(layoutAutoreF);
    layoutFumetto->addLayout(layoutNumeroUscitaF);
    layoutFumetto->addLayout(layoutEditoreF);

    layoutRivista->addLayout(layoutNumeroUscitaR);
    layoutRivista->addLayout(layoutEditoreR);

    layoutElemento->addWidget(libro);
    layoutElemento->addWidget(fumetto);
    layoutElemento->addWidget(rivista);

    layoutTipo->addWidget(mensile);
    layoutTipo->addWidget(settimanale);

    dettagliBase->setLayout(layoutItemBase);
    boxElementoSelezionato->setLayout(layoutElemento);
    dettagliLibro->setLayout(layoutLibro);
    dettagliFumetto->setLayout(layoutFumetto);
    dettagliRivista->setLayout(layoutRivista);
    boxTipoSelezionato->setLayout(layoutTipo);

    dettagliLibro->setVisible(false);
    dettagliFumetto->setVisible(false);
    dettagliRivista->setVisible(false);
    boxTipoSelezionato->setVisible(false);

    griglia->addWidget(dettagliBase, 0,0);
    griglia->addWidget(boxElementoSelezionato, 0,1);
    griglia->addWidget(dettagliLibro, 1,0);
    griglia->addWidget(dettagliFumetto, 1,0);
    griglia->addWidget(dettagliRivista, 1,0);
    griglia->addWidget(boxTipoSelezionato, 1,1);
    griglia->addWidget(no, 2,0);
    griglia->addWidget(ok, 2,1);

    dettagliBase->setFixedWidth(300);
    boxElementoSelezionato->setFixedWidth(300);
    dettagliLibro->setFixedWidth(300);
    dettagliFumetto->setFixedWidth(300);
    dettagliRivista->setFixedWidth(300);
    boxTipoSelezionato->setFixedWidth(300);

    layoutInserimentoPrincipale->addLayout(griglia);
    setLayout(layoutInserimentoPrincipale);
    setWindowTitle("Inserimento dati");

    connect(libro, SIGNAL(clicked()), this, SLOT(showLibro()));
    connect(fumetto, SIGNAL(clicked()), this, SLOT(showFumetto()));
    connect(rivista, SIGNAL(clicked()), this, SLOT(showRivista()));
    connect(ok, SIGNAL(clicked()), this, SLOT(conferma()));
    connect(no, SIGNAL(clicked()), this, SLOT(annulla()));

}

void FinestraDiInserimento::resetPerNuovoInserimento() {
    dettagliBase->setVisible(false);
    boxElementoSelezionato->setVisible(false);
    dettagliLibro->setVisible(false);
    dettagliFumetto->setVisible(false);
    dettagliRivista->setVisible(false);
    boxTipoSelezionato->setVisible(false);

    this->adjustSize();

    titolo->setText("--Vuoto--");
    genere->setText("--Vuoto--");
    prezzo->setText("0.0");
    prezzoNoleggio->setText("0.0");
    autoreL->setText("--Vuoto--");
    autoreF->setText("--Vuoto--");
    editoreL->setText("--Vuoto--");
    editoreF->setText("--Vuoto--");
    editoreR->setText("--Vuoto--");
    annoEdizione->setText("--Vuoto--");
    numeroUscitaF->setText("0");
    numeroUscitaR->setText("0");

    libro->setChecked(false);

    fumetto->setChecked(false);

    rivista->setChecked(false);

    settimanale->setAutoExclusive(true);
    settimanale->setChecked(false);

    mensile->setAutoExclusive(true);
    mensile->setChecked(false);

    dettagliBase->setVisible(true);
    boxElementoSelezionato->setVisible(true);

    this->adjustSize();
}

void FinestraDiInserimento::displayErroreInput() {
    QMessageBox messaggio;
    messaggio.critical(this, "Errore", "Input Errato");
    messaggio.setFixedSize(500, 200);
}

void FinestraDiInserimento::showLibro() {

    dettagliBase->setVisible(false);
    boxElementoSelezionato->setVisible(false);
    boxTipoSelezionato->setVisible(false);
    dettagliLibro->setVisible(false);
    dettagliFumetto->setVisible(false);
    dettagliRivista->setVisible(false);

    this->adjustSize();

    dettagliBase->setVisible(true);
    boxElementoSelezionato->setVisible(true);
    dettagliLibro->setVisible(true);

    this->adjustSize();
}

void FinestraDiInserimento::showFumetto() {
    dettagliBase->setVisible(false);
    boxElementoSelezionato->setVisible(false);
    boxTipoSelezionato->setVisible(false);
    dettagliLibro->setVisible(false);
    dettagliFumetto->setVisible(false);
    dettagliRivista->setVisible(false);

    this->adjustSize();

    dettagliBase->setVisible(true);
    boxElementoSelezionato->setVisible(true);
    dettagliFumetto->setVisible(true);

    this->adjustSize();
}

void FinestraDiInserimento::showRivista() {
    dettagliBase->setVisible(false);
    boxElementoSelezionato->setVisible(false);
    boxTipoSelezionato->setVisible(false);
    dettagliLibro->setVisible(false);
    dettagliFumetto->setVisible(false);
    dettagliRivista->setVisible(false);

    this->adjustSize();

    mensile->setChecked(false);
    settimanale->setChecked(false);

    dettagliBase->setVisible(true);
    boxElementoSelezionato->setVisible(true);
    boxTipoSelezionato->setVisible(true);
    dettagliRivista->setVisible(true);

    this->adjustSize();
}

void FinestraDiInserimento::conferma() {
    QRegExp regexNumber("^(?:0|[1-9][0-9]*)\\.[0-9]+$");
    QStringList *tmp = new QStringList();

    if (libro->isChecked())
        tmp->push_back("l");
    else {
        if (fumetto->isChecked())
            tmp->push_back("f");
        else {
            if (settimanale->isChecked())
                tmp->push_back("s");
            else {
                if (mensile->isChecked())
                    tmp->push_back("m");
                else
                    tmp->push_back("null");
            }
        }
    }

    tmp->push_back(titolo->text());
    tmp->push_back(genere->text());
    tmp->push_back(prezzo->text());
    tmp->push_back(prezzoNoleggio->text());
    if (libro->isChecked()) {
        tmp->push_back(autoreL->text());
        tmp->push_back(annoEdizione->text());
        tmp->push_back(editoreL->text());
    }
    if (fumetto->isChecked()) {
        tmp->push_back(autoreF->text());
        tmp->push_back(numeroUscitaF->text());
        tmp->push_back(editoreF->text());
    }
    if (settimanale->isChecked()) {
        tmp->push_back(numeroUscitaR->text());
        tmp->push_back(editoreR->text());
        tmp->push_back(settimanale->isChecked() ? "true":"false");
        tmp->push_back(mensile->isChecked() ? "true":"false");
    }
    if (mensile->isChecked()) {
        tmp->push_back(numeroUscitaR->text());
        tmp->push_back(editoreR->text());
        tmp->push_back(settimanale->isChecked() ? "true":"false");
        tmp->push_back(mensile->isChecked() ? "true":"false");
    }

    if (prezzo->text().contains(regexNumber)) {
        emit mandaDettagliOggetto(*tmp);
        this->close();
    }
    else
        emit erroreInput();
}

void FinestraDiInserimento::annulla() {
    this->resetPerNuovoInserimento();
    this->close();
}
