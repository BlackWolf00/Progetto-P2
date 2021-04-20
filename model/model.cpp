#include "model.h"

Model::Model(QObject *parent)
    : QObject(parent), data(QDate::currentDate()), catalogo(), noleggio(), acquisto(), filename() {}

void Model::aggiungiAcquisto(const unsigned int i, const unsigned int q) {
    DeepPtr<Item> inserisci(catalogo.searchAtIndex(i));
    acquisto.inserisciNelCarrello(inserisci, q);
    emit acquistoAggiunto();
}

/*bool Model::modificaOggetto(const unsigned int i, const QStringList l) {
    if(l.at(0) != "null") {
        DeepPtr<Item> elemento;
        if(l.at(0) == "l")
            elemento = new Libro(l.at(1).toStdString(), l.at(2).toStdString(), l.at(3).toDouble(),
                                 l.at(4).toStdString(), l.at(5).toStdString(), l.at(6).toStdString());
        if(l.at(0) == "f")
            elemento = new Fumetto(l.at(1).toStdString(), l.at(2).toStdString(), l.at(3).toDouble(),
                                   l.at(4).toInt(), l.at(5).toStdString(), l.at(6).toStdString());
        if(l.at(0) == "m")
            elemento = new Mensile(l.at(1).toStdString(), l.at(2).toStdString(), l.at(3).toDouble(),
                                   l.at(4).toInt(), l.at(5).toStdString());
        if(l.at(0) == "s")
            elemento = new Settimanale(l.at(1).toStdString(), l.at(2).toStdString(), l.at(3).toDouble(),
                                       l.at(4).toInt(), l.at(5).toStdString());

        catalogo.replaceAtIndex(elemento, i);
        return true;
    }

    return false;
}*/

void Model::rimuoviDaCatalogo(const unsigned int i) {
    catalogo.removeOneAtIndex(i);
    emit catalogoRimosso();
}

void Model::rimuoviAcquisto(const unsigned int i) {
    acquisto.eliminaDaCarrelloAIndice(i);
    emit acquistoRimosso();
}

/*QString Model::getDettagliCatalogo(const unsigned int i) const {
    return QString::fromStdString((catalogo.searchAtIndex(i))->print());
}*/

QStringList Model::getElementiCatalogo(const unsigned int i) const {
    QStringList stampa;
    if(dynamic_cast<const Libro*>(&(*(catalogo.searchAtIndex(i))))) {
        const Libro* item = static_cast<const Libro*>(&(*(catalogo.searchAtIndex(i))));
        stampa.push_back("l");
        stampa.push_back(QString::fromStdString(dynamic_cast<const Libro*>(&(*(catalogo.searchAtIndex(i))))->getTitolo()));
        stampa.push_back(QString::fromStdString(dynamic_cast<const Libro*>(&(*(catalogo.searchAtIndex(i))))->getGenere()));
        stampa.push_back(QString::number(item->getPrezzo()));
        stampa.push_back(QString::fromStdString(dynamic_cast<const Libro*>(&(*(catalogo.searchAtIndex(i))))->getAutore()));
        stampa.push_back(QString::fromStdString(dynamic_cast<const Libro*>(&(*(catalogo.searchAtIndex(i))))->getAnnoEdizione()));
        stampa.push_back(QString::fromStdString(dynamic_cast<const Libro*>(&(*(catalogo.searchAtIndex(i))))->getEditore()));
    }
    else {
        if(dynamic_cast<const Fumetto*>(&(*(catalogo.searchAtIndex(i))))) {
            const Fumetto* item = static_cast<const Fumetto*>(&(*(catalogo.searchAtIndex(i))));
            stampa.push_back("f");
            stampa.push_back(QString::fromStdString(dynamic_cast<const Fumetto*>(&(*(catalogo.searchAtIndex(i))))->getTitolo()));
            stampa.push_back(QString::fromStdString(dynamic_cast<const Fumetto*>(&(*(catalogo.searchAtIndex(i))))->getGenere()));
            stampa.push_back(QString::number(item->getPrezzo()));
            stampa.push_back(QString::number(item->getNumeroUscita()));
            stampa.push_back(QString::fromStdString(dynamic_cast<const Fumetto*>(&(*(catalogo.searchAtIndex(i))))->getAutore()));
            stampa.push_back(QString::fromStdString(dynamic_cast<const Fumetto*>(&(*(catalogo.searchAtIndex(i))))->getEditore()));
        }
        else {
            if(dynamic_cast<const Settimanale*>(&(*(catalogo.searchAtIndex(i))))) {
                const Settimanale* item = static_cast<const Settimanale*>(&(*(catalogo.searchAtIndex(i))));
                stampa.push_back("s");
                stampa.push_back(QString::fromStdString(dynamic_cast<const Settimanale*>(&(*(catalogo.searchAtIndex(i))))->getTitolo()));
                stampa.push_back(QString::fromStdString(dynamic_cast<const Settimanale*>(&(*(catalogo.searchAtIndex(i))))->getGenere()));
                stampa.push_back(QString::number(item->getPrezzo()));
                stampa.push_back(QString::number(item->getNumeroUscita()));
                stampa.push_back(QString::fromStdString(dynamic_cast<const Settimanale*>(&(*(catalogo.searchAtIndex(i))))->getEditore()));
            }
            else {
                if(dynamic_cast<const Mensile*>(&(*(catalogo.searchAtIndex(i))))) {
                    const Mensile* item = static_cast<const Mensile*>(&(*(catalogo.searchAtIndex(i))));
                    stampa.push_back("m");
                    stampa.push_back(QString::fromStdString(dynamic_cast<const Mensile*>(&(*(catalogo.searchAtIndex(i))))->getTitolo()));
                    stampa.push_back(QString::fromStdString(dynamic_cast<const Mensile*>(&(*(catalogo.searchAtIndex(i))))->getGenere()));
                    stampa.push_back(QString::number(item->getPrezzo()));
                    stampa.push_back(QString::number(item->getNumeroUscita()));
                    stampa.push_back(QString::fromStdString(dynamic_cast<const Mensile*>(&(*(catalogo.searchAtIndex(i))))->getEditore()));
                }
                else
                    stampa.push_back("null");
            }
        }
    }
    return stampa;
}

QStringList Model::getElementiAcquisto(const unsigned int i) const {
    QStringList stampa;
    if(dynamic_cast<const Libro*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()))) {
        const Libro* item = dynamic_cast<const Libro*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()));
        stampa.push_back("l");
        stampa.push_back(QString::fromStdString(item->getTitolo()));
        stampa.push_back(QString::fromStdString(item->getGenere()));
        stampa.push_back(QString::number(item->getPrezzo()));
        stampa.push_back(QString::fromStdString(item->getAutore()));
        stampa.push_back(QString::fromStdString(item->getAnnoEdizione()));
        stampa.push_back(QString::fromStdString(item->getEditore()));
    }
    else {
        if(dynamic_cast<const Fumetto*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()))) {
            const Fumetto* item = dynamic_cast<const Fumetto*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()));
            stampa.push_back("f");
            stampa.push_back(QString::fromStdString(item->getTitolo()));
            stampa.push_back(QString::fromStdString(item->getGenere()));
            stampa.push_back(QString::number(item->getPrezzo()));
            stampa.push_back(QString::number(item->getNumeroUscita()));
            stampa.push_back(QString::fromStdString(item->getAutore()));
            stampa.push_back(QString::fromStdString(item->getEditore()));
        }
        else {
           if (dynamic_cast<const Settimanale*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()))) {
               const Settimanale* item = dynamic_cast<const Settimanale*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()));
               stampa.push_back("s");
               stampa.push_back(QString::fromStdString(item->getTitolo()));
               stampa.push_back(QString::fromStdString(item->getGenere()));
               stampa.push_back(QString::number(item->getPrezzo()));
               stampa.push_back(QString::number(item->getNumeroUscita()));
               stampa.push_back(QString::fromStdString(item->getEditore()));
           }
           else {
               if (dynamic_cast<const Mensile*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()))) {
                   const Mensile* item = dynamic_cast<const Mensile*>(&(*(acquisto.cercaNelCarrello(catalogo.searchAtIndex(i))).key()));
                   stampa.push_back("s");
                   stampa.push_back(QString::fromStdString(item->getTitolo()));
                   stampa.push_back(QString::fromStdString(item->getGenere()));
                   stampa.push_back(QString::number(item->getPrezzo()));
                   stampa.push_back(QString::number(item->getNumeroUscita()));
                   stampa.push_back(QString::fromStdString(item->getEditore()));
               }
               else
                   stampa.push_back("null");
           }
        }
    }

    return stampa;
}

unsigned int Model::getQuantitaAcquisto(const unsigned int i) const {
    return acquisto.cercaNelCarrello(catalogo.searchAtIndex(i)).value();
}

void Model::setQuantitaAcquisto(const unsigned int i, const unsigned int q) {
    DeepPtr<Item> tmp = catalogo.searchAtIndex(i);
    acquisto.setQuantita(tmp, q);
}

QStringList Model::getCatalogo() const {
    QStringList stampa;
    QString label;
    auto it = catalogo.begin();
    if(!catalogo.is_empty()) {
        while(it != catalogo.end()) {
            label = (QString::fromStdString((*(*it)).getTitolo() + " " + (*(*it)).getGenere()) + " " );
            stampa.push_back(label);
            ++it;
        }
    }

    return stampa;
}

QStringList Model::getCatalogoFiltrato(const QString filtro, QMap<unsigned int, unsigned int> &map) const {
    QStringList stampa;
    QString label;
    QRegExp regex(filtro, Qt::CaseInsensitive, QRegExp::Wildcard);
    auto it = catalogo.begin();
    unsigned int count = 0;
    if(!catalogo.is_empty()) {
        while(it!=catalogo.end()) {
            label = (QString::fromStdString((*(*it)).getTitolo() + " " + (*(*it)).getGenere()) + " ");
            if(label.contains(regex)) {
                map.insert((uint)stampa.count(), count);
                stampa.push_back(label);
            }
            count++;
            ++it;
        }
    }

    return stampa;
}

QStringList Model::getAcquisto() const {

}

double Model::getPrezziAcquisto() const {
    return acquisto.getTotalePrezzoAcquisto();
}

bool Model::controllaNelCatalogo(const QStringList d) const {

}

unsigned int Model::trovaElementoNelCatalogo(const QStringList d) const {

}

bool Model::trovatoQualcosa() const {
    return !catalogo.is_empty() || !acquisto.is_vuoto();
}

void Model::pulisciSpazio() {
    catalogo = Container<DeepPtr<Item>> ();
    acquisto = Carrello();
}

void Model::setData(const QDate d) {
    data = d;
}

QDate Model::getData() const {
    return data;
}

void Model::aggiungiNelCatalogo(const QStringList e) {

}

void Model::setFilename(const QString flname) {
    filename = flname;
}

QString Model::caricaDati() {

}
