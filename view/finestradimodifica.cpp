#include "finestradimodifica.h"

FinestraDiModifica::FinestraDiModifica(QWidget *parent) : FinestraDiInserimento(parent) {}

void FinestraDiModifica::caricaDataPerModifica(const QStringList l, const unsigned int i) {
    ind = i;

    QString punto = "\\.";
    QRegExp trovaPunto(punto);

    if (l.at(0) == "l") {
        dettagliLibro->setVisible(true);
        dettagliFumetto->setVisible(false);
        dettagliRivista->setVisible(false);
        boxTipoSelezionato->setVisible(false);

        this->adjustSize();

        libro->setChecked(true);
        titolo->setText(l.at(1));
        genere->setText(l.at(2));
        if(l.at(3).contains(trovaPunto))
            prezzo->setText(l.at(3));
        else
            prezzo->setText(l.at(3)+".0");
        if(l.at(4).contains(trovaPunto))
            prezzoNoleggio->setText(l.at(4));
        else
            prezzoNoleggio->setText(l.at(4) + ".0");
        autoreL->setText(l.at(5));
        annoEdizione->setText(l.at(6));
        editoreL->setText(l.at(7));
    }
    else {
        if (l.at(0) == "f") {
            dettagliLibro->setVisible(false);
            dettagliFumetto->setVisible(true);
            dettagliRivista->setVisible(false);
            boxTipoSelezionato->setVisible(false);

            this->adjustSize();

            fumetto->setChecked(true);
            titolo->setText(l.at(1));
            genere->setText(l.at(2));
            if(l.at(3).contains(trovaPunto))
                prezzo->setText(l.at(3));
            else
                prezzo->setText(l.at(3)+".0");
            if(l.at(4).contains(trovaPunto))
                prezzoNoleggio->setText(l.at(4));
            else
                prezzoNoleggio->setText(l.at(4) + ".0");
            autoreF->setText(l.at(5));
            numeroUscitaF->setText(l.at(6));
            editoreF->setText(l.at(7));
        }
        else {
            if (l.at(0) == "s") {
                dettagliLibro->setVisible(false);
                dettagliFumetto->setVisible(false);
                dettagliRivista->setVisible(true);
                boxTipoSelezionato->setVisible(true);

                this->adjustSize();

                rivista->setChecked(true);
                settimanale->setAutoExclusive(true);
                settimanale->setChecked(true);

                titolo->setText(l.at(1));
                genere->setText(l.at(2));
                if(l.at(3).contains(trovaPunto))
                    prezzo->setText(l.at(3));
                else
                    prezzo->setText(l.at(3)+".0");
                if(l.at(4).contains(trovaPunto))
                    prezzoNoleggio->setText(l.at(4));
                else
                    prezzoNoleggio->setText(l.at(4) + ".0");
                numeroUscitaR->setText(l.at(5));
                editoreR->setText(l.at(6));
                settimanale->setChecked(l.at(7) == "true" ? true:false);
                mensile->setChecked(l.at(8) == "true" ? true:false);
            }
            else {
                if (l.at(0) == "m") {
                    dettagliLibro->setVisible(false);
                    dettagliFumetto->setVisible(false);
                    dettagliRivista->setVisible(true);
                    boxTipoSelezionato->setVisible(true);

                    this->adjustSize();

                    rivista->setChecked(true);
                    mensile->setAutoExclusive(true);
                    mensile->setChecked(true);

                    titolo->setText(l.at(1));
                    genere->setText(l.at(2));
                    if(l.at(3).contains(trovaPunto))
                        prezzo->setText(l.at(3));
                    else
                        prezzo->setText(l.at(3)+".0");
                    if(l.at(4).contains(trovaPunto))
                        prezzoNoleggio->setText(l.at(4));
                    else
                        prezzoNoleggio->setText(l.at(4) + ".0");
                    numeroUscitaR->setText(l.at(5));
                    editoreR->setText(l.at(6));
                    settimanale->setChecked(l.at(7) == "true" ? true:false);
                    mensile->setChecked(l.at(8) == "true" ? true:false);
                }
                else {
                    dettagliLibro->setVisible(false);
                    dettagliFumetto->setVisible(false);
                    dettagliRivista->setVisible(false);

                    this->adjustSize();
                }
            }
        }
    }
}

void FinestraDiModifica::conferma() {
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

    if (prezzo->text().contains(regexNumber) && prezzoNoleggio->text().contains(regexNumber)) {
        emit rimpiazzaOggetto(ind, *tmp);
        this->close();
    }
    else
        emit erroreInput();
}
