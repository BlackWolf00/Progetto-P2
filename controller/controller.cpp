#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent), modello(new Model(this)), finestraP(new FinestraPrincipale(this)),
    finestraI(new FinestraDiInserimento(finestraP)), finestraM(new FinestraDiModifica(finestraP)) {

    finestraP->show();

    connect(finestraP, SIGNAL(clickAcquisto(const unsigned int, const unsigned int)), this,
            SLOT(aggiungiAdAcquisto(const unsigned int, const unsigned int)));
    connect(finestraP, SIGNAL(clickNoleggio(const unsigned int,const unsigned int)), this,
            SLOT(aggiungiANoleggio(const unsigned int,const unsigned int)));

    connect(finestraP, SIGNAL(richiestaRimuoviDaCatalogo(const unsigned int)), this,
            SLOT(removeCatalogo(const unsigned int)));
    connect(finestraP, SIGNAL(clickRimuoviAcquisto(const unsigned int)), this,
            SLOT(removeAcquisto(const unsigned int)));
    connect(finestraP, SIGNAL(clickRimuoviNoleggio(const unsigned int)), this,
            SLOT(removeNoleggio(const unsigned int)));

    connect(finestraP, SIGNAL(richiestaDettagliCatalogo(const unsigned int)), this,
            SLOT(getDettagliCatalogo(const unsigned int)));
    connect(finestraP, SIGNAL(richiestaDettagliAcquisto(const unsigned int)), this,
            SLOT(getDettagliAcquisto(const unsigned int)));
    connect(finestraP, SIGNAL(richiestaDettagliNoleggio(const unsigned int)), this,
            SLOT(getDettagliNoleggio(const unsigned int)));

    connect(finestraP, SIGNAL(apriFinestraAggiungiACatalogo()), this, SLOT(apriAggiungi()));
    connect(finestraP, SIGNAL(richiestaModifica()), this, SLOT(apriModifica()));
    connect(finestraP, SIGNAL(apriFinestraSalvataggio()), this, SLOT(apriSalva()));
    connect(finestraP, SIGNAL(apriFinestraCaricamento()), this, SLOT(apriCarica()));
    connect(finestraP, SIGNAL(apriFinestraSalvaPDF()), this, SLOT(apriSalvaPDF()));
    connect(finestraP, SIGNAL(aggiornaRicerca()), this, SLOT(refreshCatalogo()));

    connect(finestraI, SIGNAL(mandaDettagliOggetto(const QStringList)), this, SLOT(aggiungiACatalogo(const QStringList)));
    connect(finestraI, SIGNAL(erroreInput()), this, SLOT(erroreInput()));

    connect(finestraM, SIGNAL(rimpiazzaOggetto(const unsigned int, const QStringList)), this,
            SLOT(sendPerScambio(const unsigned int, QStringList)));
    connect(finestraM, SIGNAL(erroreInput()), this, SLOT(erroreInput()));

    connect(modello, SIGNAL(elementoAggiunto()), this, SLOT(refreshCatalogo()));
    connect(modello, SIGNAL(acquistoAggiunto()), this, SLOT(refreshAcquisto()));
    connect(modello, SIGNAL(noleggioAggiuto()), this, SLOT(refreshNoleggio()));

    connect(modello, SIGNAL(catalogoRimosso()), this, SLOT(refreshCatalogo()));
    connect(modello, SIGNAL(acquistoRimosso()), this, SLOT(refreshAcquisto()));
    connect(modello, SIGNAL(noleggioRimosso()), this, SLOT(refreshNoleggio()));
}

void Controller::scambiaNelCatalogo(const unsigned int i, const QStringList dettagli) {
    modello->modificaOggetto(indexTranslate[i], dettagli);
}

void Controller::aggiungiACatalogo(const QStringList dettagli) {
    if(dettagli.first() == "null")
        finestraP->displayErroreInput();
    else {
        if(dettagli[1] == "null")
            finestraP->displayErroreInput();
        else{
            if(!modello->controllaNelCatalogo(dettagli))
                modello->aggiungiNelCatalogo(dettagli);
            else {
                finestraP->displayElementoEsistente();
            }
        }
    }
}

void Controller::aggiungiAdAcquisto(const unsigned int i, const unsigned int q) {
    if(q != 0)
        modello->aggiungiAcquisto(indexTranslate[i], q);
}

void Controller::aggiungiANoleggio(const unsigned int i, const unsigned int q) {
    if(q != 0)
        modello->aggiungiNolleggio(indexTranslate[i], q);
}

void Controller::removeCatalogo(const unsigned int i) {
    modello->rimuoviDaCatalogo(indexTranslate[i]);
    refreshCatalogo();
}

void Controller::removeAcquisto(const unsigned int i) {
    modello->rimuoviAcquisto(i);
}

void Controller::removeNoleggio(const unsigned int i) {
    modello->rimuoviNoleggio(i);
}

void Controller::getDettagliCatalogo(const unsigned int i) const {
    finestraP->displayDettagli(modello->getDettagliCatalogo(indexTranslate[i]));
}

void Controller::getDettagliAcquisto(const unsigned int i) const {
    finestraP->displayDettagli(modello->getDettagliAcquisto(i));
}

void Controller::getDettagliNoleggio(const unsigned int i) const {
    finestraP->displayDettagli(modello->getDettagliNoleggio(i));
}

void Controller::sendPerScambio(const unsigned int i, const QStringList elemento) {
    modello->modificaOggetto(indexTranslate[i], elemento);
    refreshCatalogo();
}

void Controller::refreshCatalogo() {
    QString filter = finestraP->getParolaChiave();
    finestraP->displayCatalogo(modello->getCatalogoFiltrato(filter, indexTranslate));
}

void Controller::refreshAcquisto() {
    finestraP->displayAcquisto(modello->getAcquisto());
    finestraP->displayTotale(modello->getPrezziNoleggio(), modello->getPrezziAcquisto());
}

void Controller::refreshNoleggio() {
    finestraP->displayNoleggio(modello->getNoleggio());
    finestraP->displayTotale(modello->getPrezziNoleggio(), modello->getPrezziAcquisto());
}

void Controller::apriAggiungi() const {
    finestraI->resetPerNuovoInserimento();
    finestraI->setModal(true);
    finestraI->show();
}

void Controller::apriModifica() const {
    if(finestraP->isSelezionato()) {
        finestraM->caricaDataPerModifica(modello->getElementiCatalogo(finestraP->getCatalogoSelezionato()),
                                         finestraP->getCatalogoSelezionato());
        finestraM->setModal(true);
        finestraM->show();
    }
    else
        finestraP->displayNessunaSelezione();
}

void Controller::apriSalva() const {
    QString file = QFileDialog::getSaveFileName(finestraP, "Salva Catalogo", "../progetto/cataloghi", "Catalogo (*.xml)");
    if(file == "")
        modello->setFilename("catalogo.xml");
    else {
        if(!file.endsWith(".xml"))
            file = file + ".xml";
        modello->setFilename(file);
        finestraP->displaySalva(modello->serializzaDati());
    }
}

void Controller::apriCarica() {
    QString file = QFileDialog::getOpenFileName(finestraP, "Carica Catalogo", "../progetto/cataloghi", "Catalogo (*.xml)");
    if(file == "")
        finestraP->displayErroreApertura();
    else {
        if(modello->trovatoQualcosa())
            modello->pulisciSpazio();
        modello->setFilename(file);
        finestraP->displayCarica(modello->caricaDati());
        refreshCatalogo();
        refreshNoleggio();
        refreshAcquisto();
    }
}

void Controller::apriSalvaPDF() const {
    QString file = QFileDialog::getSaveFileName(finestraP, "Salva PDF", "../progetto/PDF");
    if(file == "")
        file = ("Preventivo_" + modello->getData().toString("dmy") + ".xml");
    else {
        if(!file.endsWith(".pdf"))
            file = file + ".pdf";
        QStringList r = modello->getNoleggio();
        QStringList a = modello->getAcquisto();
        QPdfWriter writer(file);
        QPainter painter(&writer);
        painter.setPen(Qt::black);

        painter.drawText(100, 200, "Cliente: " + finestraP->getNomeCliente());
        painter.drawText(3750, 200, "CF: " + finestraP->getCFCliente());
        painter.drawText(7750, 200, "Data: " + modello->getData().toString());
        painter.drawText(1600, 1000, "Noleggi");
        painter.drawText(6300, 1000, "Acquisti");

        int l = 800, a1 = 1400;
        auto noleggio_it = r.begin();
        while(noleggio_it != r.end()) {
            painter.drawText(l, a1, *noleggio_it);
            noleggio_it++;
            a1+=300;
        }

        l = 5800;
        int a2 = 1400;
        auto acquisto_it = a.begin();
        while (acquisto_it != a.end()) {
            painter.drawText(l, a2, *acquisto_it);
            acquisto_it++;
            a2 += 300;
        }
        if(a1 > a2) {
            painter.drawText(950, a1+500, "Totale noleggio: " + QString::number(modello->getPrezziNoleggio()) + "€");
            painter.drawText(5950, a1+500, "Totale comprato: " + QString::number(modello->getPrezziAcquisto()) + "€");
        }
        else {
            painter.drawText(950, a2+500, "Totale comprato: " + QString::number(modello->getPrezziNoleggio()) + "€");
            painter.drawText(5950, a2+500, "Totale comprato: " + QString::number(modello->getPrezziAcquisto()) + "€");
        }

        painter.drawText(200, 13700, "Preventivo BiblioTech");
        painter.end();
    }
}

void Controller::erroreInput() {
    finestraI->displayErroreInput();
}
