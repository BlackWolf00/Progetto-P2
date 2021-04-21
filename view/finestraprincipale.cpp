#include "finestraprincipale.h"

FinestraPrincipale::FinestraPrincipale(QWidget *parent)
    : QMainWindow(parent), dettagli(new QLabel("--Dettagli--", this)),
      totnoleggio(new QLabel("0€", this)), totacquisto(new QLabel("0€", this)),
      elemento(new ListaSmart(this)), noleggio(new ListaSmart(this)), acquisto(new ListaSmart(this)),
      data(new QDateEdit(QDate::currentDate(), this)), quantita(new QSpinBox(this)),
      nome(new QLineEdit("Cliente", this)), cf(new QLineEdit("CF", this)),
      trova(new QLineEdit(this)) {

    elemento->setSelectionMode(QAbstractItemView::SingleSelection);
    noleggio->setSelectionMode(QAbstractItemView::SingleSelection);
    acquisto->setSelectionMode(QAbstractItemView::SingleSelection);

    QWidget *widgetPrincipale = new QWidget(this);
    QVBoxLayout *layoutPrincipale = new QVBoxLayout();
    QMenuBar *menu = new QMenuBar(this);
    QMenu *file = new QMenu("File", this);
    QMenu *modifica = new QMenu("Modifica", this);
    QAction *aggiungiACatalogo = new QAction("Aggiungi elemento al catalogo", this);
    QAction *rimuoviDaCatalogo = new QAction("Rimuovi elemento dal catalogo", this);
    QAction *modificaElementoCatalogo = new QAction("Modifica elemento del catalogo", this);
    QAction *carica = new QAction("Carica file", this);
    QAction *salva = new QAction("Salva file", this);
    QAction *pdf = new QAction("Esporta PDF", this);
    QAction *exit = new QAction("Esci", this);
    QLabel *labelNome = new QLabel("Nome: ");
    QLabel *labelCf = new QLabel("CF: ");
    QLabel *labelData = new QLabel("Data: ");
    QLabel *labelCatalogo = new QLabel("Catalogo: ");
    QLabel *labelCerca = new QLabel("Cerca: ");
    QLabel *labelNoleggio = new QLabel("Noleggio: ");
    QLabel *labelAcquisto = new QLabel("Acquisto: ");
    QLabel *labelQuantita = new QLabel("Quantita: ");
    QLabel *labelTotNoleggio = new QLabel("Totale Noleggio: ");
    QLabel *labelTotAcquisto = new QLabel("Totale Acquisto: ");

    //BOTTONI

    QPushButton *bottoneNoleggio = new QPushButton("Noleggia");
    QPushButton *bottoneAcquisto = new QPushButton("Acquista");
    QPushButton *bottoneRimuoviNoleggio = new QPushButton("Rimuovi noleggio");
    QPushButton *bottoneRimuoviAcquisto = new QPushButton("Rimuovi acquisto");

    //DEFINIZIONE LAYOUT

    QVBoxLayout *boxContinua = new QVBoxLayout();
    QVBoxLayout *boxLabelParziali = new QVBoxLayout();
    QVBoxLayout *boxValoriParziali = new QVBoxLayout();
    QHBoxLayout *boxParziali = new QHBoxLayout();
    QHBoxLayout *boxFinale = new QHBoxLayout();

    QVBoxLayout *quantitaBottoni = new QVBoxLayout();
    QHBoxLayout *scriviQuantita = new QHBoxLayout();
    QHBoxLayout *dueBottoni = new QHBoxLayout();

    QHBoxLayout *dueListe = new QHBoxLayout();
    QVBoxLayout *boxNoleggio = new QVBoxLayout();
    QVBoxLayout *boxAcquisto = new QVBoxLayout();

    QHBoxLayout *continuaDettagli = new QHBoxLayout();
    QVBoxLayout *continuaElemento = new QVBoxLayout();

    QVBoxLayout *sezioneCerca = new QVBoxLayout();

    QVBoxLayout *destra = new QVBoxLayout();
    QVBoxLayout *sinistra = new QVBoxLayout();

    QHBoxLayout *principale = new QHBoxLayout();
    QVBoxLayout *layoutFinale = new QVBoxLayout();

    QHBoxLayout *dettagliCliente = new QHBoxLayout();

    //AGGIUNTA LAYOUT

    menu->addMenu(file);
    menu->addMenu(modifica);

    modifica->addAction(aggiungiACatalogo);
    modifica->addAction(rimuoviDaCatalogo);
    modifica->addAction(modificaElementoCatalogo);

    file->addAction(carica);
    file->addAction(salva);
    file->addAction(pdf);
    file->addAction(exit);

    boxContinua->addLayout(boxParziali);
    boxContinua->addLayout(boxFinale);

    boxParziali->addLayout(boxLabelParziali);
    boxParziali->addLayout(boxValoriParziali);

    boxLabelParziali->addWidget(labelTotNoleggio);
    boxLabelParziali->addWidget(labelTotAcquisto);

    boxValoriParziali->addWidget(totnoleggio);
    boxValoriParziali->addWidget(totacquisto);

    noleggio->deselezionaIndice();
    acquisto->deselezionaIndice();

    quantitaBottoni->addLayout(scriviQuantita);
    quantitaBottoni->addLayout(dueBottoni);

    scriviQuantita->addWidget(labelQuantita);
    scriviQuantita->addWidget(quantita);

    dueBottoni->addWidget(bottoneNoleggio);
    dueBottoni->addWidget(bottoneAcquisto);

    dueListe->addLayout(boxNoleggio);
    dueListe->addLayout(boxAcquisto);

    boxNoleggio->addWidget(labelNoleggio);
    boxNoleggio->addWidget(noleggio);
    boxNoleggio->addWidget(bottoneRimuoviNoleggio);

    boxAcquisto->addWidget(labelAcquisto);
    boxAcquisto->addWidget(acquisto);
    boxAcquisto->addWidget(bottoneRimuoviAcquisto);

    continuaDettagli->addWidget(dettagli);

    sezioneCerca->addWidget(labelCerca);
    sezioneCerca->addWidget(trova);

    continuaElemento->addWidget(labelCatalogo);
    continuaElemento->addWidget(elemento);

    destra->addLayout(continuaDettagli);
    destra->addLayout(dueListe);
    destra->addLayout(boxContinua);
    principale->addLayout(destra);

    sinistra->addLayout(continuaElemento);
    sinistra->addLayout(quantitaBottoni);
    sinistra->addLayout(sezioneCerca);
    principale->addLayout(sinistra);

    dettagliCliente->addWidget(labelNome);
    dettagliCliente->addWidget(nome);
    dettagliCliente->addWidget(labelCf);
    dettagliCliente->addWidget(cf);
    dettagliCliente->addWidget(labelData);
    dettagliCliente->addWidget(data);
    layoutFinale->addLayout(dettagliCliente);

    layoutFinale->addLayout(principale);
    layoutPrincipale->addLayout(layoutFinale);

    layoutPrincipale->addWidget(menu);
    widgetPrincipale->setLayout(layoutPrincipale);
    setCentralWidget(widgetPrincipale);

    dettagli->setMinimumHeight(300);
    dettagli->setMinimumWidth(300);

    //CONNESSIONI

    connect(carica, SIGNAL(triggered()), SIGNAL(apriFinestraCaricamento()));
    connect(salva, SIGNAL(triggered()), SIGNAL(apriFinestraSalvataggio()));
    connect(pdf, SIGNAL(triggered()), SIGNAL(apriFinestraSalvaPDF()));
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));
    connect(aggiungiACatalogo, SIGNAL(triggered()), this, SIGNAL(apriFinestraAggiungiACatalogo()));
    connect(rimuoviDaCatalogo, SIGNAL(triggered()), this, SLOT(rimuoviSelezionato()));
    connect(modificaElementoCatalogo, SIGNAL(triggered()), this, SIGNAL(richiestaModifica()));
    connect(trova, SIGNAL(textChanged(const QString &)), this, SIGNAL(aggiornaRicerca()));
    connect(bottoneNoleggio, SIGNAL(clicked()), this, SLOT(generaNoleggio()));
    connect(bottoneAcquisto, SIGNAL(clicked()), this, SLOT(generaAcquisto()));
    connect(bottoneRimuoviNoleggio, SIGNAL(clicked()), this, SLOT(distruggiNoleggio()));
    connect(bottoneRimuoviAcquisto, SIGNAL(clicked()), this, SLOT(distruggiAcquisto()));
    connect(elemento, SIGNAL(currentRowChanged(const int)), this, SLOT(catalogoSelezionato(const int)));
    connect(noleggio, SIGNAL(currentRowChanged(const int)), this, SLOT(noleggioSelezionato(const int)));
    connect(acquisto, SIGNAL(currentRowChanged(const int)), this, SLOT(acquistoSelezionato(const int)));

}

void FinestraPrincipale::displayCatalogo(const QStringList l) {
    elemento->reset();
    elemento->clear();
    auto it = l.begin();
    while(it != l.end()) {
        elemento->addItem(*it);
        ++it;
    }
}

void FinestraPrincipale::displayNoleggio(const QStringList l) {
    noleggio->reset();
    noleggio->clear();
    auto it = l.begin();
    while(it != l.end()) {
        noleggio->addItem(*it);
        ++it;
    }
}

void FinestraPrincipale::displayAcquisto(const QStringList l) {
    acquisto->reset();
    acquisto->clear();
    auto it = l.begin();
    while(it != l.end()) {
        acquisto->addItem(*it);
        ++it;
    }
}

void FinestraPrincipale::displayErroreInput() {
    QMessageBox message;
    message.critical(this, "Errore", "Input Incompleto");
    message.setFixedSize(500, 200);
}

void FinestraPrincipale::displayNessunaSelezione() {
    QMessageBox message;
    message.critical(this, "Errore", "Nessun oggetto selezionato");
    message.setFixedSize(500, 200);
}

void FinestraPrincipale::displayDettagli(const QString d) {
    dettagli->clear();
    dettagli->setText(d);
}

void FinestraPrincipale::displayTotale(const double n, const double c) {
    totnoleggio->clear();
    totnoleggio->setText(QString::number(n)+"€");

    totacquisto->clear();
    totacquisto->setText(QString::number(c)+"€");
}

void FinestraPrincipale::displayErroreApertura() {
    QMessageBox message;
    message.critical(this, "Errore", "Impossibile aprire il file selezionato");
    message.setFixedSize(500, 200);
}

void FinestraPrincipale::displayElementoEsistente() {
    QMessageBox message;
    message.critical(this, "Errore", "Elemento già esistente");
    message.setFixedSize(500, 200);
}

void FinestraPrincipale::displayCarica(QString e) {
    QMessageBox message;
    message.warning(this, "Conferma", e);
    message.setFixedSize(500, 200);
}

void FinestraPrincipale::displaySalva(QString e) {
    QMessageBox message;
    message.warning(this, "Conferma", e);
    message.setFixedSize(500, 200);
}

bool FinestraPrincipale::isSelezionato() const {
    return elemento->isGiaSelezionato();
}

unsigned int FinestraPrincipale::getCatalogoSelezionato() const {
    return elemento->getIndice();
}

const QString FinestraPrincipale::getParolaChiave() const {
    return trova->text();
}

QString FinestraPrincipale::getNomeCliente() const {
    return nome->text();
}

QString FinestraPrincipale::getCFCliente() const {
    return cf->text();
}

void FinestraPrincipale::aggiornaDettagli(QString info) {
    dettagli->setText(info);
}

void FinestraPrincipale::generaNoleggio() {
    if(elemento->isGiaSelezionato()) {
        emit clickNoleggio(elemento->getIndice(), (uint)quantita->value());
        quantita->setValue(0);
    }
    else
        displayNessunaSelezione();
}

void FinestraPrincipale::generaAcquisto() {
    if(elemento->isGiaSelezionato()) {
        emit clickAcquisto(elemento->getIndice(), (uint)quantita->value());
        quantita->setValue(0);
    }
    else
        displayNessunaSelezione();
}

void FinestraPrincipale::distruggiNoleggio() {
    if(noleggio->isGiaSelezionato())
        emit clickRimuoviNoleggio(noleggio->getIndice());
    else
        displayNessunaSelezione();
}

void FinestraPrincipale::distruggiAcquisto() {
    if(acquisto->isGiaSelezionato())
        emit clickRimuoviAcquisto(acquisto->getIndice());
    else
        displayNessunaSelezione();
}

void FinestraPrincipale::catalogoSelezionato(const int i) {
    noleggio->reset();
    acquisto->reset();
    emit richiestaDettagliCatalogo((uint)i);
}

void FinestraPrincipale::noleggioSelezionato(const int i) {
    elemento->reset();
    acquisto->reset();
    emit richiestaDettagliNoleggio((uint)i);
}

void FinestraPrincipale::acquistoSelezionato(const int i) {
    elemento->reset();
    noleggio->reset();
    emit richiestaDettagliAcquisto((uint)i);
}

void FinestraPrincipale::rimuoviSelezionato() {
    if(elemento->isGiaSelezionato())
        emit richiestaRimuoviDaCatalogo(elemento->getIndice());
    else
        displayNessunaSelezione();
}
