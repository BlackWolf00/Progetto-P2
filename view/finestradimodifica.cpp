#include "finestradimodifica.h"

FinestraDiModifica::FinestraDiModifica(QWidget *parent) : FinestraDiInserimento(parent) {}

void FinestraDiModifica::caricaDataPerModifica(const QStringList l, const unsigned int i) {
    i = i;

    QString punto = "\\.";
    QRegExp trovaPunto(punto);

    if (l.at(0) == "l") {
        dettagliLibro->setVisible(true);
        dettagliFumetto->setVisible(false);
        dettagliSettimanale->setVisible(false);
        dettagliMensile->setVisible(false);

        this->adjustSize();

        libro->setChecked(true);
        titolo->setText(l.at(1));
        genere->setText(l.at(2));
        if(l.at(3).contains(trovaPunto))
            prezzo->setText(l.at(3));
        else
            prezzo->setText(l.at(3)+".0");
        autore->setText(l.at(4));
        annoEdizione->setText(l.at(5));
        editore->setText(l.at(6));
    }
    else {
        if (l.at(0) == "f") {
            dettagliLibro->setVisible(false);
            dettagliFumetto->setVisible(true);
            dettagliSettimanale->setVisible(false);
            dettagliMensile->setVisible(false);

            this->adjustSize();

            fumetto->setChecked(true);
            titolo->setText(l.at(1));
            genere->setText(l.at(2));
            if(l.at(3).contains(trovaPunto))
                prezzo->setText(l.at(3));
            else
                prezzo->setText(l.at(3)+".0");
            numeroUscita->setText(l.at(4));
            autore->setText(l.at(5));
            editore->setText(l.at(6));
        }
        else {
            if (l.at(0) == "s") {
                dettagliLibro->setVisible(false);
                dettagliFumetto->setVisible(false);
                dettagliSettimanale->setVisible(true);
                dettagliMensile->setVisible(false);

                this->adjustSize();

                settimanale->setChecked(true);
                titolo->setText(l.at(1));
                genere->setText(l.at(2));
                if(l.at(3).contains(trovaPunto))
                    prezzo->setText(l.at(3));
                else
                    prezzo->setText(l.at(3)+".0");
                numeroUscita->setText(l.at(4));
                editore->setText(l.at(5));
            }
            else {
                if (l.at(0) == "m") {
                    dettagliLibro->setVisible(false);
                    dettagliFumetto->setVisible(false);
                    dettagliSettimanale->setVisible(false);
                    dettagliMensile->setVisible(true);

                    this->adjustSize();

                    mensile->setChecked(true);
                    titolo->setText(l.at(1));
                    genere->setText(l.at(2));
                    if(l.at(3).contains(trovaPunto))
                        prezzo->setText(l.at(3));
                    else
                        prezzo->setText(l.at(3)+".0");
                    numeroUscita->setText(l.at(4));
                    editore->setText(l.at(5));
                }
                else {
                    dettagliLibro->setVisible(false);
                    dettagliFumetto->setVisible(false);
                    dettagliSettimanale->setVisible(false);
                    dettagliMensile->setVisible(false);

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
    if (libro->isChecked()) {
        tmp->push_back(autore->text());
        tmp->push_back(annoEdizione->text());
        tmp->push_back(editore->text());
    }
    if (fumetto->isChecked()) {
        tmp->push_back(numeroUscita->text());
        tmp->push_back(autore->text());
        tmp->push_back(editore->text());
    }
    if (settimanale->isChecked() || mensile->isChecked()) {
        tmp->push_back(numeroUscita->text());
        tmp->push_back(editore->text());
    }

    if (prezzo->text().contains(regexNumber)) {
        emit mandaDettagliOggetto(*tmp);
        this->close();
    }
    else
        emit erroreInput();
}
